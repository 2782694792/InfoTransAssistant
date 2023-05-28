#include "TcpClient.h"
#include <regex>
#include <vector>
//#include <QtNetwork\qtcpsocket.h>

#define	SERVER_PORT				4096			// 端口号
#define SERVER_IP			"127.0.0.1"	// server端的IP地址

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

TcpClient::TcpClient(QObject* parent = nullptr) :QObject(parent)
{
	InitSocket();
}

TcpClient::TcpClient(const char * ip, int port, bool isBlocking, int timeout = 0) : m_ip(ip), m_port(port), QObject(nullptr), m_isBlocking(isBlocking), m_timeout(timeout)
{
	InitSocket();
}

TcpClient::~TcpClient()
{
	// 释放winsock库
	::WSACleanup();
}

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
	if (SOCKET_ERROR == (m_client = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) // 指定地址族、套接字类型、协议
	{
		LOGE_(TPStr.SOCKET_INIT_FAILURE.toStdString());

		return false;
	}

	LOGI_(TPStr.SOCKET_INIT_SUCCESS.toStdString());

	return true;
}

bool TcpClient::ConectToServer()
{
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
	
	struct sockaddr_in local_addr;
	int len = sizeof(local_addr);
	memset(&local_addr, 0, len);
	getsockname(m_client, (struct sockaddr*) &local_addr, &len);
	m_localPort = std::to_string(ntohs(local_addr.sin_port));
	//if (SOCKET_ERROR == rest)
	//{		
	//	record_result(TP::UNCONNECT, &m_client, TPStr.UNCONNECT);
	//}

	/*iResult = ioctlsocket(m_client, FIONBIO, &iMode);
	if (iResult != NO_ERROR)
	{
	if (m_isBlocking)
	{
	LOGE_(TPStr.SOCKET_BLOCKING.toStdString());
	}
	else
	{
	LOGI_(TPStr.SOCKET_NON_BLOCKING.toStdString());
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
	}*/

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

		return false;
	}

	record_result(TP::CONNECT, &m_client, TPStr.CONNECT);

	return true;
}

// 发送服务端
bool TcpClient::SendDataToServer(const char * data)
{
	record_result(TP::SENDING, &m_client, data);

	if (SOCKET_ERROR == ::send(m_client, data, MAXFILEDIRLENGTH, 0))
	{
		record_result(TP::SEND_FAILURE, &m_client, data);
		//exit(-1);

		return false;
	}

	record_result(TP::SEND_SUCCESS, &m_client, data);

	return true;
}

// 处理server端传送过来的消息
void TcpClient::RecvServerMsg()
{
	int nRecv = ::recv(m_client, m_recvBuff, MAX_PACKET_SIZE + 1, 0);

	for (int i = 0; i < 64; i++)
	{
		printf("%d", m_recvBuff[i]);
	}

	record_result(TP::RECVING_REQUEST_DATA, &m_client, m_recvBuff);
}

// 关闭socket库
bool TcpClient::DisConnect()
{
	record_result(TP::DISCONNECT, &m_client, TPStr.DISCONNECT);

	::closesocket(m_client); // 关闭套接字

	return true;
}

// 获取本地端口
std::string TcpClient::getLocalPort() {
	return m_localPort;
}

// 记录客户端操作结果
TP TcpClient::record_result(TP result, const SOCKET* client,
	const QString & data){
	std::string id = "", temp = "", id2 = "", temp2 = "";
	QString log = "";
	std::string localport = getLocalPort(); // 获取IP地址
	bool isrecv = false;

	if (client != nullptr) {
		temp = std::string("[%1] > [%2: %3] %4\n"); // 本地 > 目标

		temp2 = std::string("[%1: %2] > [%3] %4\n"); // 目标 > 本地
	}

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
		log = data;
		isrecv = true;
		break;
	case belien::identification::TP::STOP_RECVED_REQUEST_DATA:
		break;
	case belien::identification::TP::RESPONSE_CONNECT_REQUEST:
		break;
	case belien::identification::TP::SENDING:
		break;
	case belien::identification::TP::SEND_SUCCESS:
		log = TPStr.SEND_SUCCESS;
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
		std::vector<std::string> idv2{ m_ip, std::to_string(m_port), localport, log.toLocal8Bit().data() };
		id2 = replace_string(temp, idv2);
		m_log = QString::fromLocal8Bit(id2.data());
	}
	else
	{
		std::vector<std::string> idv{ localport, m_ip, std::to_string(m_port), log.toLocal8Bit().data() };
		id = replace_string(temp, idv);
		m_log = QString::fromLocal8Bit(id.data());
	}
	
	emit logReady(m_log);
	
	return result;
}
