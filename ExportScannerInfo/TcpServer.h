#pragma once
#include <QThread>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/qtcpserver.h>
#include <qmutex.h>
#include <qset.h>
#include <qvector.h>
#include "belien\identification.h"
#include "belien\log.h"
using namespace belien::identification;
using namespace belien::log;

class TcpServer : public QThread {
    Q_OBJECT

public:
    TcpServer(QObject* parent = nullptr) : QThread(parent){};
    explicit TcpServer(int port);
    ~TcpServer();

protected:
    void run() override;

signals:
    void logReady(const QString& log); // ׼����¼�ͻ��˲�����־
    void updateClientsReady();         // �ͻ����������׼��

public slots:
    void onNewConnection(); // ����������
    void onReadyRead();     // ��ʼ��������������
    TPServer doDisconnected(); // �Ͽ�����

public:
    TPServer startListen();    // ��ʼ����
    TPServer stopListen();     // ֹͣ����
    TPServer disconnectedOne(QString addr, int port); // �Ͽ�ָ���ͻ�������
    TPServer disconnectedAll(); // �Ͽ����пͻ�������

    TPServer getStatus() {
        return m_status;
    }                            // ��ȡ����˵�ǰ״̬
	bool isListen(); // ��ȡ����״̬

    void startRecvRequestData(); // ��ʼ����
    void stopRecvRequestData();  // ��ͣ����

    int  getClientsCount();      // ��ȡ���ӵĿͻ�������
    void getClientsInfo(QStringList& addrs, QList< int >& ports);

    TPServer sendDataToClient(int repeatNum, const std::string & message); // �������ݵ����пͻ���
    TPServer sendDataToClient(QString addr, int port, int repeatNum, const std::string & message); // ָ�������������ݵ�ָ���ͻ���

    TPServer record_result(TPServer, const QTcpSocket*,
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
    TPServer            m_status;  // ��ǰ������״̬
    QString             m_log;     // ��־��¼

public:
    int    m_port; // ��ǰ�˿�
    QMutex m_mx;   // �����������������ؽ�������
};
