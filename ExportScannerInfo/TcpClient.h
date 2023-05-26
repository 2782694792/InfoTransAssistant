#pragma once

#include <iostream>
#include <WinSock2.h>
#include <stdio.h>
#include <assert.h>
#pragma comment(lib, "WS2_32")
#include "belien\identification.h"
#include "belien\log.h"
using namespace belien::identification;
using namespace belien::log;

#define MAX_PACKET_SIZE		10240			// ���ݰ�����󳤶�,��λ��sizeof(char)
#define	MAXFILEDIRLENGTH	256				// ����ļ�·������󳤶�

class TcpClient
{
public:
	TcpClient();
	~TcpClient();

private:

	bool InitSocket(); // ��ʼ��socket��

	bool ConectToServer(const char * ip, const int port); // ��server�����ӽ��д���

	bool SendDataToServer();	// ���û���������ݴ��͵�server��
	
	bool ProcessMsg();	// ����server�˴��͹�������Ϣ
	
	bool CloseSocket();	// �ر�socket��

	void getLocalPort(); // ��ȡ���ض˿�

private:

	char	m_recvBuff[MAX_PACKET_SIZE + 1];
	SOCKET	m_client;
};