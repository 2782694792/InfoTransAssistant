#pragma once
#include "qdialog.h"
#include "ui_TCPC_AddConnect.h"
#include <QTableWidgetItem>
#include <vector>
#include "IpAndPort.h"
#include "belien\identification.h"
#include "belien\log.h"
using namespace belien::identification;
using namespace belien::log;

class Connection;

namespace Ui {
    class FORM_TCPC_ADD_CONNECT;
}

class FORM_TCPC_ADD_CONNECT :
	public QDialog
{
    Q_OBJECT;

public:
	explicit FORM_TCPC_ADD_CONNECT(QWidget *parent = nullptr);
	~FORM_TCPC_ADD_CONNECT();

signals:
    void startLogTcpcConnection(const std::vector<Connection>& connection); // 返回记录连接信息

	private slots:
	void onClicked_PB_TARGET_CONNECT_INFO_INSERT(); // 插入新行

	void onClicked_PB_TARGET_CONNECT_INFO_DELETE(); // 删除新行

	void onClicked_PB_TARGET_CONNECT_INFO_REFRESH(); // 应用刷新

private:
    Ui::FORM_TCPC_ADD_CONNECT ui;
	
	std::vector<Connection> m_connection;

};

class Connection {
public:
    Connection() :
        m_ip("127.0.0.1"), m_port(5000), m_connected(false) {}

    Connection(const QString& ip, int port, bool connected = false) :
        m_ip(ip), m_port(port), m_connected(connected) {}

    void setIP(const QString& ip) { m_ip = ip; }
    QString getIP() const { return m_ip; }

    void setPort(int port) { m_port = port; }
    int getPort() const { return m_port; }

    void setConnected(bool connected) { m_connected = connected; }
    bool isConnected() const { return m_connected; }

private:
    QString m_ip;
    int m_port;
    bool m_connected;
};
