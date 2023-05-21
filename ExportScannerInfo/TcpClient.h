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
#define	PORT				4096			// �˿ں�
#define SERVER_IP			"127.0.0.1"	// server�˵�IP��ַ
SOCKET	g_sClient;
char	g_szBuff[MAX_PACKET_SIZE + 1];

class TcpClient
{
public:
	TcpClient();
	~TcpClient();

public:

private:
	// ��ʼ��socket��
	bool InitSocket()
	{
		LOGI_("InitSocket() invoke begin");

		// ��ʼ��socket dll
		WSADATA wsaData;
		WORD socketVersion = MAKEWORD(2, 2);
		if (::WSAStartup(socketVersion, &wsaData) != 0)
		{
			LOGE_("Init socket dll error\n");
			exit(-1);
		}
		printf("InitSocket() invoke end return true \n");
		return true;
	}

	// ��server�����ӽ��д���
	bool ConectToServer()
	{
		// ��ʼ��socket�׽���
		if (SOCKET_ERROR == (g_sClient = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)))
		{
			printf("Init Socket Error!\n");
			exit(-1);
		}
		sockaddr_in servAddr;
		servAddr.sin_family = AF_INET;
		servAddr.sin_port = htons(PORT);
		servAddr.sin_addr.S_un.S_addr = ::inet_addr(SERVER_IP);
		if (INVALID_SOCKET == (::connect(g_sClient, (sockaddr*)&servAddr, sizeof(sockaddr_in))))
		{
			printf("Connect to Server Error!\n");
			exit(-1);
		}

		// �������ݴ��䵽server��
		while (SendDataToServer())
		{
		}

		// ����server�˴���������Ϣ,ֱ�������ļ��ɹ�Ϊֹ
		while (ProcessMsg())
		{
		}

		return true;
	}

	// ���û���������ݴ��͵�server��
	bool SendDataToServer()
	{
		char Data[MAXFILEDIRLENGTH];
		printf("Input the Data: \n");

		fgets(Data, MAXFILEDIRLENGTH, stdin);

		for (int i = 0; i < MAXFILEDIRLENGTH; i++)
		{
			Data[i] = Data[i] - 48;
		}
		if (SOCKET_ERROR == ::send(g_sClient, (char*)(&Data), 256, 0))
		{
			printf("Send Data Error!\n");
			exit(-1);
		}

		return true;
	}

	// ����server�˴��͹�������Ϣ
	bool ProcessMsg()
	{
		int nRecv = ::recv(g_sClient, g_szBuff, MAX_PACKET_SIZE + 1, 0);

		for (int i = 0; i < 64; i++)
		{
			printf("%d ", g_szBuff[i]);
		}
		printf("\n");

		return true;
	}

	// �ر�socket��
	bool CloseSocket()
	{
		// �ر��׽���
		::closesocket(g_sClient);
		// �ͷ�winsock��
		::WSACleanup();

		return true;
	}

};