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

	bool InitSocket(); // 初始化socket库

	bool ConectToServer(const char * ip, const int port); // 与server端连接进行传输

	bool SendDataToServer();	// 把用户输入的数据传送到server端

	const std::string & ProcessMsg();	// 处理server端传送过来的消息

	bool CloseSocket();	// 关闭socket库

	const std::string & getLocalPort(); // 获取本地端口

private:
	SOCKET	m_client;
};