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

#define MAX_PACKET_SIZE		10240			// 数据包的最大长度,单位是sizeof(char)
#define	MAXFILEDIRLENGTH	256				// 存放文件路径的最大长度

class TcpClient
{
public:
	TcpClient();
	~TcpClient();

private:

	bool InitSocket(); // 初始化socket库

	bool ConectToServer(const char * ip, const int port); // 与server端连接进行传输

	bool SendDataToServer();	// 把用户输入的数据传送到server端
	
	bool ProcessMsg();	// 处理server端传送过来的消息
	
	bool CloseSocket();	// 关闭socket库

	void getLocalPort(); // 获取本地端口

private:

	char	m_recvBuff[MAX_PACKET_SIZE + 1];
	SOCKET	m_client;
};