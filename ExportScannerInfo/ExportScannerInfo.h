#pragma once

#include "ClickableLabel.h"
#include "TcpServer.h"
#include "ui_ExportScannerInfo.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QtWidgets/QMainWindow>
#include <vector>
// #include <thread>
// const int numThreads = std::thread::hardware_concurrency();
static int listenNum = 0;

class ExportScannerInfo : public QMainWindow {
    Q_OBJECT;

public:
    ExportScannerInfo(QWidget* parent = Q_NULLPTR);

    void getTcpsRest(const QString& result);

private:
    ClickableLabel* label;
    void init_sidebar_label(TextLabelID tlid); // ��ʼ���������ǩ
    void clear_sidebar_label();

signals:
    void startGetTcpsLog();

private slots:
    void onClickableLabel_Clicked();             // label ����л�����

    void onClicked_PB_TCPS_LISTEN_PORT_CREATE(); // �˿����
    void onClicked_PB_TCPS_LISTEN_PORT_DELETE(); // �˿�ɾ��
    void onCurrentIndexChanged_CB_TCPS_LISTEN_PORT_LIST(); // �˿��л�

    void onClicked_PB_TCPS_LISTENING();                    // �����˿ڼ���
    void onClicked_PB_TCPS_LISTENED();                     // ֹͣ�˿ڼ���

    void onClicked_PB_TCPS_START_RECV_CONTENT(); // ����������������
    void onClicked_PB_TCPS_STOP_RECV_CONTENT();  // ��ͣ����

    void onUpdateClients(); // ���¿ͻ�����Ϣ����ֹ��ȡ socket

    void onCurrentindexChanged_CB_TCPS_CONTENT_CLIENT_IP(); // �ͻ���ָ����Ϣ

	void onStateChanged_CHB_TCPS_ALL_CLIENT(); // ѡ�����пͻ���

	void onClicked_PB_TCPS_DISCONNECT_CLIENT(); // �Ͽ��ͻ���

	void onClicked_PB_TCPS_SEND_CLIENT(); // ���Ϳͻ���

public:
#ifdef test_eventFilter
    bool eventFilter(QObject* obj, QEvent* event) override; // �¼�������
    void init_register_eventFilter();
#endif

private:
    void init_main_slots();
    void init_qss();                        // ��ʼ����ťԲ��
    void init_default_widget();             // ��ʼ������Ч��
    void init_member();                     // ��ʼ����Ա����
    void init_ctrl_visible(bool isVisible); // ��ʼ���ؼ���ʾ

    void isListen_change_control_status();

    void prompt_operation_status(
        bool isSuccess, const QString& labelContent) const; // ��ǩ��ʾ����״̬

    int currentTCPS() const; // ���ؼ���������ǰ�����

	void onUpdateTcpsRecvOrNone(); // ���·�����Ƿ����

protected:
    void paintEvent(QPaintEvent* event) override;   // ���»滭������

    void resizeEvent(QResizeEvent* event) override; // ����Ӧ�ֱ��ʴ�С

private:
    Ui::ExportScannerInfoClass ui;
    std::vector< TcpServer* > m_tcps;       // ����˼���
    QStringList               m_ClientAddr; // �ͻ��˵�ַ
    QList< int >              m_ClientPort; // �ͻ��˶˿�
	QString					  m_log;
};
