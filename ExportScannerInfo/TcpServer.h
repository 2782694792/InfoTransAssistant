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
    void logReady(const QString& log); // ׼����¼�ͻ��˲�����־
    void updateClientsReady();         // �ͻ����������׼��

public slots:
    void onNewConnection(); // ����������
    void onReadyRead();     // ��ʼ��������������
    TP doDisconnected(); // �Ͽ�����

public:
    TP startListen();    // ��ʼ����
    TP stopListen();     // ֹͣ����
    TP disconnectedOne(QString addr, int port); // �Ͽ�ָ���ͻ�������
    TP disconnectedAll(); // �Ͽ����пͻ�������

    TP getStatus() {
        return m_status;
    }                            // ��ȡ����˵�ǰ״̬
	bool isListen(); // ��ȡ����״̬

    void startRecvRequestData(); // ��ʼ����
    void stopRecvRequestData();  // ��ͣ����

    int  getClientsCount();      // ��ȡ���ӵĿͻ�������
    void getClientsInfo(QStringList& addrs, QList< int >& ports);

    TP sendDataToClient(int repeatNum, const std::string & message); // �������ݵ����пͻ���
    TP sendDataToClient(QString addr, int port, int repeatNum, const std::string & message); // ָ�������������ݵ�ָ���ͻ���

    TP record_result(TP, const QTcpSocket*,
                           const QByteArray& data = NULL); // ��¼�ͻ��˲������

    QString getLog() {
        return m_log;
    } // ��ȡ��¼��־
	void    clearLog() {
        m_log.clear();
    } // �����־��¼

    void closeServer(); // �رյ�ǰ������
	
private:
    QTcpServer*         m_server;  // ��ǰ�����
    QSet< QTcpSocket* > m_clients; // �ͻ��˼���
    TP					m_status;  // ��ǰ������״̬
    QString             m_log;     // ��־��¼

public:
    int    m_port; // ��ǰ�˿�
    QMutex m_mx;   // �����������������ؽ�������
};
