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
    void logReady(const QString & log); // ׼����¼�ͻ��˲�����־

public:
	std::string getIp(){ return m_ip; };

	int getPort(){ return m_port; };
	
	bool InitSocket(); // ��ʼ��socket��

	bool ConectToServer(); // ��server�����ӽ��д���

	bool SendDataToServer(const char * data);	// ���û���������ݴ��͵�server��
	
	void RecvServerMsg();	// ����server�˴��͹�������Ϣ
	
	bool DisConnect();	// �ر�socket��

	std::string getLocalPort(); // ��ȡ���ض˿�

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