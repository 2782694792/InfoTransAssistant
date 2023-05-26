#pragma once

#include <iostream>
#include <WinSock2.h>
#include <stdio.h>
#include <assert.h>
#include <string>
#pragma comment(lib, "WS2_32")

#include "belien\identification.h"
#include "belien\log.h"
#include "belien\IpAndPort.h"
using namespace belien::identification;
using namespace belien::log;
using namespace belien::ip_port;

class TcpClient
{
public:
	TcpClient();
	~TcpClient();

private:

	bool InitSocket(); // ��ʼ��socket��

	bool ConectToServer(const char * ip, const int port); // ��server�����ӽ��д���

	bool SendDataToServer();	// ���û���������ݴ��͵�server��

	const std::string & ProcessMsg();	// ����server�˴��͹�������Ϣ

	bool CloseSocket();	// �ر�socket��

	const std::string & getLocalPort(); // ��ȡ���ض˿�

private:
	SOCKET	m_client;
};