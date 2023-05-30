#include "TcpClient.h"
#include <regex>
#include <vector>
#include <qpushbutton.h>
#include <TCPC_AddConnect.h>

static std::string replace_string(const std::string& content, const std::vector<std::string>& args) {
	std::string result = content;
	std::regex r("%(\\d)");
	std::smatch match_result;
	while (std::regex_search(result, match_result, r)) {
		int idx = std::stoi(match_result[1]);
		if (idx > 0 && idx <= args.size()) {
			result.replace(match_result.position(), match_result[0].length(), args[idx - 1]);
		}
	}
	return result;
}

TcpClient::TcpClient(QObject* parent) : m_parent(parent)
{
	m_recv_length = 0;
	InitSocket();
}

TcpClient::TcpClient(const char * ip, int port, bool isBlocking, int timeout = 0, QObject* parent) : m_ip(ip), m_port(port), m_parent(nullptr), m_isBlocking(isBlocking), m_timeout(timeout)
{
	InitSocket();
}

TcpClient::~TcpClient()
{
	// 释放winsock库
	::WSACleanup();
}

// 连接初始化
bool TcpClient::InitSocket()
{
	// 初始化socket dll
	WSADATA wsaData;
	WORD socketVersion = MAKEWORD(2, 2);
	if (::WSAStartup(socketVersion, &wsaData) != 0)
	{
		LOGE_(TPStr.SOCKET_INIT_FAILURE.toStdString());

		return false;
	}

	// 初始化socket套接字
	if (INVALID_SOCKET == (m_client = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) // 指定地址族、套接字类型、协议
	{
		LOGE_(TPStr.SOCKET_INIT_FAILURE.toStdString());
		// 释放winsock库
		::WSACleanup();
		return false;
	}

	LOGI_(TPStr.SOCKET_INIT_SUCCESS.toStdString());

	return true;
}

//#include "Loading.h"
// 连接服务端
bool TcpClient::ConectToServer()
{
	LOGI_(TPStr.REQUEST_CONNECT.toStdString().data());

	//Form_Loading *load = new Form_Loading();
	//load->show();

	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(m_port);
	inet_pton(AF_INET, m_ip.data(), &servAddr.sin_addr);

	unsigned long iMode = m_isBlocking ? 0 : 1; // 0 阻塞
	int iResult = ioctlsocket(m_client, FIONBIO, &iMode);
	if (iResult != NO_ERROR)
	{
		if (m_isBlocking)
		{
			LOGE_(TPStr.SOCKET_BLOCKING.toStdString());
		}
		else
		{
			LOGE_(TPStr.SOCKET_NON_BLOCKING.toStdString());
		}
	}
	else
	{
		if (m_isBlocking)
		{
			LOGI_(TPStr.SOCKET_BLOCKING.toStdString());
		}
		else
		{
			LOGI_(TPStr.SOCKET_NON_BLOCKING.toStdString());
		}
	}

	int rest = ::connect(m_client, (struct sockaddr*)&servAddr, sizeof(sockaddr_in));
	if (rest == SOCKET_ERROR)
	{
		//closesocket(m_client);
	}
	
	fd_set Write, Err;
	FD_ZERO(&Write);
	FD_ZERO(&Err);
	FD_SET(m_client, &Write);
	FD_SET(m_client, &Err);

	//check if the socket is ready
	TIMEVAL timeout;
	timeout.tv_sec = m_timeout;
	timeout.tv_usec = 0;
	select(0, NULL, &Write, &Err, &timeout);
	if (!FD_ISSET(m_client, &Write))
	{
		record_result(TP::UNCONNECT, &m_client, TPStr.UNCONNECT);
		closesocket(m_client);
		m_client = INVALID_SOCKET;

		//delete load;

		return false;
	}

	record_result(TP::CONNECT, &m_client, TPStr.CONNECT);

	//delete load;

	return true;
}

// 发送服务端
bool TcpClient::SendDataToServer(const char * data)
{
	if (SOCKET_ERROR == ::send(m_client, data, MAXFILEDIRLENGTH, 0))
	{
		record_result(TP::SEND_FAILURE, &m_client, data);

		return false;
	}

	record_result(TP::SEND_SUCCESS, &m_client, QString::fromLocal8Bit(data));

	return true;
}

// 处理server端传送过来的消息
void TcpClient::RecvServerMsg()
{
	if (m_client == INVALID_SOCKET) {
		record_result(TP::UNCONNECT, &m_client, TPStr.UNCONNECT);
		WSACleanup();

		return;
	}
	
	int nRecv = 0;
	m_stopRecv = false;
	memset(m_recvBuff, 0, MAX_PACKET_SIZE);
	do {
		nRecv = ::recv(m_client, m_recvBuff, MAX_PACKET_SIZE + 1, 0);
		if (nRecv > 0) {
			// TODO: 整理字节接收统计（接收则更新、客户端连接断开进行清空处理）
			m_recv_length += nRecv;
			//LOGI("(%d Bytes) %.*s\n", nRecv, nRecv, m_recvBuff);
			QString recvbuf = QString("%1").arg(m_recvBuff);
			record_result(TP::RECV_SUCCESS, &m_client, recvbuf);
		}
		else if (nRecv == 0){
			if (!m_stopRecv)
			{
				DisConnect(); // 关闭套接字
				emit readyDisconnectFromServer();
			}
			break;
		}
		else{
			//LOGE_(TPStr.RECV_FAILURE.toStdString());
		}
	} while (!m_stopRecv);
}

//void TcpClient::DisconnectToParent(){
//	QPushButton * p_disconnect = m_parent.findChild<QPushButton*>("PB_TCPC_DISCONNECT");
//	QPushButton * p_connect = m_parent.findChild<QPushButton*>("PB_TCPC_CONNECT");
//	QPushButton * p_startrecv = m_parent.findChild<QPushButton*>("PB_TCPC_START_RECV_CONTENT");
//	QPushButton * p_stoprecv = m_parent.findChild<QPushButton*>("PB_TCPC_STOP_RECV_CONTENT");
//	p_disconnect->setEnabled(false);
//	p_connect->setEnabled(true);
//	p_startrecv->setEnabled(false);
//	p_stoprecv->setEnabled(false);
//}

// 关闭socket库
bool TcpClient::DisConnect()
{
	m_stopRecv = true;

	record_result(TP::DISCONNECT, &m_client, TPStr.DISCONNECT);
	::closesocket(m_client); // 关闭套接字
	m_stopRecv = false;

	return true;
}

// 获取本地端口
std::string TcpClient::getLocalPort() {
	std::string localPort;

	struct sockaddr_in local_addr;
	int len = sizeof(local_addr);
	memset(&local_addr, 0, len);
	getsockname(m_client, (struct sockaddr*) &local_addr, &len);
	localPort = std::to_string(ntohs(local_addr.sin_port));

	return localPort;
}

// 记录客户端操作结果
TP TcpClient::record_result(TP result, const SOCKET* client,
	const QString & data){
	std::string id = "", temp = "", id2 = "", temp2 = "";
	QString log = "";
	std::string localport = getLocalPort(); // 获取IP地址
	bool isrecv = false;

	if (client != nullptr) {
		temp = std::string("[%1: %2] > [%3] %4\n"); // 目标 > 本地
		temp2 = std::string("[%1] > [%2: %3] %4\n"); // 目标 > 本地
	}

	memset(m_recvBuff, 0, MAX_PACKET_SIZE);

	switch (result)
	{
	case belien::identification::TP::PORT_ILLEGAL:
		break;
	case belien::identification::TP::PORT_ADDED:
		break;
	case belien::identification::TP::PORT_ADDING:
		break;
	case belien::identification::TP::SOCKET_INIT_FAILURE:
		break;
	case belien::identification::TP::SOCKET_INIT_SUCCESS:
		break;
	case belien::identification::TP::LISTENING:
		break;
	case belien::identification::TP::NOT_LISTENED:
		break;
	case belien::identification::TP::REQUEST_CONNECT:
		break;
	case belien::identification::TP::CONNECT:
		log = TPStr.CONNECT;
		break;
	case belien::identification::TP::UNCONNECT:
		log = TPStr.UNCONNECT;
		break;
	case belien::identification::TP::DISCONNECT:
		log = TPStr.DISCONNECT;
		break;
	case belien::identification::TP::RECVING_REQUEST_DATA:
		log = TPStr.RECVING_REQUEST_DATA;
		break;
	case belien::identification::TP::RECV_SUCCESS:
		log = data;
		isrecv = true;
		break;
	case belien::identification::TP::RECV_FAILURE:
		log = TPStr.RECV_FAILURE;
		break;
	case belien::identification::TP::STOP_RECVED_REQUEST_DATA:
		break;
	case belien::identification::TP::RESPONSE_CONNECT_REQUEST:
		break;
	case belien::identification::TP::SENDING:
		break;
	case belien::identification::TP::SEND_SUCCESS:
		log = data;
		break;
	case belien::identification::TP::SEND_FAILURE:
		log = TPStr.SEND_FAILURE;
		break;
	default:
		break;
	}

	LOGI_(log.toStdString().data());

	if (isrecv)
	{
		std::vector<std::string> idv{ m_ip, std::to_string(m_port), localport, log.toLocal8Bit().data() };
		id = replace_string(temp, idv);
	}
	else
	{
		std::vector<std::string> idv{ localport, m_ip, std::to_string(m_port), log.toLocal8Bit().data() };
		id = replace_string(temp2, idv);
	}
	log = QString::fromLocal8Bit(id.data());
	emit logReady(log);

	return result;
}
