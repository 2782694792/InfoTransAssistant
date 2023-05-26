#include "TcpClient.h"

#define	SERVER_PORT				4096			// 端口号
#define SERVER_IP			"127.0.0.1"	// server端的IP地址

TcpClient::TcpClient()
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
	LOGI_(QString::fromLocal8Bit("InitSocket() invoke begin"));

	// 初始化socket dll
	WSADATA wsaData;
	WORD socketVersion = MAKEWORD(2, 2);
	if (::WSAStartup(socketVersion, &wsaData) != 0)
	{
		LOGE_(QString::fromLocal8Bit("Init socket dll error"));
		exit(-1);
	}
	LOGI_(QString::fromLocal8Bit("InitSocket() invoke end return true"));
	return true;
}

bool TcpClient::ConectToServer(const char * ip, const int port)
{
	// 初始化socket套接字
	if (SOCKET_ERROR == (m_client = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) // 指定地址族、套接字类型、协议
	{
		LOGE_(QString::fromLocal8Bit("Init Socket Error!"));
		exit(-1);
	}
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(port);
	servAddr.sin_addr.S_un.S_addr = ::inet_addr(ip);
	if (INVALID_SOCKET == (::connect(m_client, (struct sockaddr*)&servAddr, sizeof(sockaddr_in))))
	{
		LOGE_(QString::fromLocal8Bit("Connect to Server Error!"));
		exit(-1);
	}

	return true;
}

bool TcpClient::SendDataToServer()
{
	char Data[MAXFILEDIRLENGTH];
	LOGI_(QString::fromLocal8Bit("Input the Data: "));

	fgets(Data, MAXFILEDIRLENGTH, stdin);

	for (int i = 0; i < MAXFILEDIRLENGTH; i++)
	{
		Data[i] = Data[i] - 48;
	}

	if (SOCKET_ERROR == ::send(m_client, (char*)(&Data), MAXFILEDIRLENGTH, 0))
	{
		LOGE_(QString::fromLocal8Bit("Send Data Error!"));
		exit(-1);
	}

	return true;
}

// 处理server端传送过来的消息
const std::string & TcpClient::ProcessMsg()
{
	char	m_recvBuff[MAX_PACKET_SIZE + 1];
	int nRecv = ::recv(m_client, m_recvBuff, MAX_PACKET_SIZE + 1, 0);

	for (int i = 0; i < 64; i++)
	{
		printf("%d", m_recvBuff[i]);
	}
	std::string temp = std::string(m_recvBuff);
	return temp;
}

// 关闭socket库
bool TcpClient::CloseSocket()
{
	::closesocket(m_client); // 关闭套接字

	return true;
}

// 获取本地端口
const std::string & TcpClient::getLocalPort() {
    struct sockaddr_in local_addr;
    int len = sizeof(local_addr);
    memset(&local_addr, 0, len);
    getsockname(m_client, (struct sockaddr*) &local_addr, &len);
	std::string temp = std::to_string(ntohs(local_addr.sin_port));

	return temp;
}