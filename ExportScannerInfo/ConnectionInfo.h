#pragma once

#include <qstring.h>

class Connection {
public:
    Connection() :
        m_ip("127.0.0.1"), m_port(-1), m_connected(false) {}

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
