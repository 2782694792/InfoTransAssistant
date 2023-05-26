#include "TcpClient.h"

#define	SERVER_PORT				4096			// �˿ں�
#define SERVER_IP			"127.0.0.1"	// server�˵�IP��ַ

TcpClient::TcpClient()
{
	InitSocket();
}


TcpClient::~TcpClient()
{
	// �ͷ�winsock��
	::WSACleanup();
}

bool TcpClient::InitSocket()
{
	LOGI_(QString::fromLocal8Bit("InitSocket() invoke begin"));

	// ��ʼ��socket dll
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
	// ��ʼ��socket�׽���
	if (SOCKET_ERROR == (m_client = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) // ָ����ַ�塢�׽������͡�Э��
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

// ����server�˴��͹�������Ϣ
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

// �ر�socket��
bool TcpClient::CloseSocket()
{
	::closesocket(m_client); // �ر��׽���

	return true;
}

// ��ȡ���ض˿�
const std::string & TcpClient::getLocalPort() {
    struct sockaddr_in local_addr;
    int len = sizeof(local_addr);
    memset(&local_addr, 0, len);
    getsockname(m_client, (struct sockaddr*) &local_addr, &len);
	std::string temp = std::to_string(ntohs(local_addr.sin_port));

	return temp;
}