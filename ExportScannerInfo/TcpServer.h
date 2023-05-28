#pragma once
#include <QThread>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/qtcpserver.h>
#include <qmutex.h>
#include <qset.h>

#include "belien\identification.h"
#include "belien\log.h"
#include "belien\tcpCheck.hpp"
using namespace belien::identification;
using namespace belien::tcpcheck;

class TcpServer : public QThread {
    Q_OBJECT

public:
    TcpServer(QObject* parent = nullptr) : QThread(parent){};
    explicit TcpServer(int port);
    ~TcpServer();

protected:
    //void run() override;

signals:
    void logReady(const QString& log); // 准备记录客户端操作日志
    void updateClientsReady();         // 客户端请求更新准备

public slots:
    void onNewConnection(); // 发现新连接
    void onReadyRead();     // 开始读连接请求数据
    TP doDisconnected(); // 断开连接

public:
    TP startListen();    // 开始监听
    TP stopListen();     // 停止监听
    TP disconnectedOne(QString addr, int port); // 断开指定客户端连接
    TP disconnectedAll(); // 断开所有客户端连接

    TP getStatus() {
        return m_status;
    }                            // 获取服务端当前状态
	bool isListen(); // 获取监听状态

    void startRecvRequestData(); // 开始接收
    void stopRecvRequestData();  // 暂停接收

    int  getClientsCount();      // 获取连接的客户端数量
    void getClientsInfo(QStringList& addrs, QList< int >& ports);

    TP sendDataToClient(int repeatNum, const std::string & message); // 发送数据到所有客户端
    TP sendDataToClient(QString addr, int port, int repeatNum, const std::string & message); // 指定次数发送数据到指定客户端

    TP record_result(TP, const QTcpSocket*,
                           const QByteArray& data = NULL); // 记录客户端操作结果

    QString getLog() {
        return m_log;
    } // 获取记录日志
	void    clearLog() {
        m_log.clear();
    } // 清空日志记录

    void closeServer(); // 关闭当前服务器
	
private:
    QTcpServer*         m_server;  // 当前服务端
    QSet< QTcpSocket* > m_clients; // 客户端集合
    TP					m_status;  // 当前服务器状态
    QString             m_log;     // 日志记录

public:
    int    m_port; // 当前端口
    QMutex m_mx;   // 互斥量控制完整返回接收内容
};
