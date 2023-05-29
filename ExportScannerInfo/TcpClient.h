#pragma once

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <WS2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#include "belien\identification.h"
#include "belien\log.h"
#include "belien\tcpCheck.hpp"
using namespace belien::identification;
using namespace belien::tcpcheck;

class TcpClient:public QObject
{
    Q_OBJECT
public:
	TcpClient(QObject* parent);
	explicit TcpClient(const char * ip, int port, bool isBlocking, int timeout);
	~TcpClient();
	
signals:
    void logReady(const QString & log); // 准备记录客户端操作日志

public:
	std::string getIp(){ return m_ip; };

	int getPort(){ return m_port; };
	
	bool InitSocket(); // 初始化socket库

	bool ConectToServer(); // 与server端连接进行传输

	bool SendDataToServer(const char * data);	// 把用户输入的数据传送到server端
	
	void RecvServerMsg();	// 处理server端传送过来的消息
	
	bool DisConnect();	// 关闭socket库

	std::string getLocalPort(); // 获取本地端口

private:
	TP record_result(TP rest, const SOCKET* client,
		const QString & data);

private:
	std::string m_ip; 
	int m_port;
	SOCKET	m_client;
	bool m_isBlocking;
	int m_timeout;
	char	m_recvBuff[MAX_PACKET_SIZE + 1];
	QString m_log;
};