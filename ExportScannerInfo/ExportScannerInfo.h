#pragma once

#include "ClickableLabel.h"
#include "TcpServer.h"
#include "ui_ExportScannerInfo.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QtWidgets/QMainWindow>
#include <vector>
#include <QSpacerItem>
#include <QPropertyAnimation>
#include "TCPC_AddConnect.h"
// #include <thread>
// const int numThreads = std::thread::hardware_concurrency();

//#define test_ctrl

static int listenNum = 0;

class ExportScannerInfo : public QMainWindow {
    Q_OBJECT;

public:
    ExportScannerInfo(QWidget* parent = Q_NULLPTR);

private:
    ClickableLabel* label;
    void init_sidebar_label(TextLabelID tlid); // ��ʼ���������ǩ
    void clear_sidebar_label();

signals:
    void startGetTcpsLog();

private slots:
    void onClickableLabel_Clicked();             // label ����л�����

#pragma region TCPS_SLOTS
	void onClicked_PB_TCPS_LISTEN_PORT_CREATE(); // �˿����
    void onClicked_PB_TCPS_LISTEN_PORT_DELETE(); // �˿�ɾ��
    void onCurrentIndexChanged_CB_TCPS_LISTEN_PORT_LIST(); // �˿��л�

    void onClicked_PB_TCPS_LISTENING();                    // �����˿ڼ���
    void onClicked_PB_TCPS_LISTENED();                     // ֹͣ�˿ڼ���

    void onClicked_PB_TCPS_START_RECV_CONTENT(); // ����������������
    void onClicked_PB_TCPS_STOP_RECV_CONTENT();  // ��ͣ����

    void onUpdateClients(); // ���¿ͻ�����Ϣ����ֹ��ȡ socket

    void onCurrentIndexChanged_CB_TCPS_CONNECT_CLIENT_IP(); // �ͻ���ָ����Ϣ

	void onStateChanged_CHB_TCPS_ALL_CLIENT(); // ѡ�����пͻ���

	void onClicked_PB_TCPS_DISCONNECT_CLIENT(); // �Ͽ��ͻ���

	void onClicked_PB_TCPS_SEND(); // ���Ϳͻ���

    void getTcpsRest(const QString& result);
#pragma endregion

#pragma region TCPC_SLOTS
	void onClicked_PB_TCPC_ADD_CONNECT(); // ��������

	void onClicked_PB_TCPC_CONNECT(); // �ͻ�������

	void onClicked_PB_TCPC_DISCONNECT(); // �ͻ��˶Ͽ�

	void onClicked_PB_TCPC_START_RECV_CONTENT(); // �ͻ��˿�ʼ����

	void onClicked_PB_TCPC_STOP_RECV_CONTENT(); // �ͻ���ֹͣ����

	void onClicked_PB_TCPC_SEND(); // �ͻ��˿�ʼ����

    void doStartLogTcpcConnection(const std::vector<Connection>& connection); // ��¼������Ϣ

#pragma endregion


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

#ifdef test_ctrl
	void test_ctrl_init();
#endif

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
	QSpacerItem	*			  m_spacerItem;
	QPropertyAnimation *	  m_animation;

	FORM_TCPC_ADD_CONNECT * m_form_tcpc_add_connect;
	std::vector<Connection>   m_tcpcConnection;
};
