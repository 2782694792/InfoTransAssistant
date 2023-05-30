#pragma once
#include "ui_ExportScannerInfo.h"

#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QtWidgets/QMainWindow>
#include <valarray>
//#include <QSpacerItem>
//#include <QPropertyAnimation>
#include <map>
#include <thread>
#include <future>
#include <qmovie.h> // ��ʾ��̬ͼ
#include <QProgressDialog>
#include "belien\work_deque\thread_pool.hpp"

#include "ClickableLabel.h"
#include "TcpServer.h"
#include "TcpClient.h"
#include "TCPC_AddConnect.h"

static int listenNum = 0;

class ExportScannerInfo : public QMainWindow {
    Q_OBJECT

public:
    ExportScannerInfo(QWidget* parent = Q_NULLPTR);
	~ExportScannerInfo();

#ifdef test_eventFilter
    bool eventFilter(QObject* obj, QEvent* event) override; // �¼�������
    void init_register_eventFilter();
#endif

protected:
    void paintEvent(QPaintEvent* event) override;   // ���»滭������

    void resizeEvent(QResizeEvent* event) override; // ����Ӧ�ֱ��ʴ�С

private slots:
    void onClickableLabel_Clicked();             // label ����л�����
	
private:
    void init_sidebar_label(TextLabelID tlid); // ��ʼ���������ǩ
    void clear_sidebar_label(); // ��ղ������ǩstyle

    void init_main_slots();
    void init_qss();                        // ��ʼ����ťԲ��
    void init_default_widget();             // ��ʼ������Ч��
    void init_member();                     // ��ʼ����Ա����
    void init_ctrl_visible(bool isVisible); // ��ʼ���ؼ���ʾ
	
private:
	QWidget * m_parent;
    Ui::ExportScannerInfoClass ui;
    ClickableLabel* label;
	std::valarray<QString> m_mainInfo;
	thread_pool m_pool;

#pragma region TCP �����
signals:
    void startGetTcpsLog(); // ��ʼ���з�����߳��Ի�ȡ������Ϣ

private slots:
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

    void getTcpsRest(const QString& result); // ��ȡ����˽��յĿͻ�����Ϣ

private:
    void isListen_change_control_status(); // ����״̬���Ŀؼ�״̬

    void prompt_operation_status(
        bool isSuccess, const QString& labelContent) const; // ��ǩ��ʾ����״̬

    int currentTCPS() const; // ���ؼ���������ǰ�����

	void onUpdateTcpsRecvOrNone(); // ���·�����Ƿ����

private:
    std::vector< TcpServer* > m_tcps;       // ����˼���
    QStringList               m_ClientAddr; // �ͻ��˵�ַ
    QList< int >              m_ClientPort; // �ͻ��˶˿�
	QString					  m_log; // ���տͻ�����Ϣ��¼
	//QSpacerItem	*			  m_spacerItem; // �ռ���
	//QPropertyAnimation *	  m_animation; // ������

#pragma endregion

#pragma region TCP �ͻ���

signals:
	void updateConnectionInfo(const std::vector<class Connection>& connection); // ����������Ϣ
	
private slots:
	void onClicked_PB_TCPC_ADD_CONNECT(); // ��������

	void onClicked_PB_TCPC_CONNECT(); // �ͻ�������

	void onClicked_PB_TCPC_DISCONNECT(); // �ͻ��˶Ͽ�

	void onClicked_PB_TCPC_START_RECV_CONTENT(); // �ͻ��˿�ʼ����

	void onClicked_PB_TCPC_STOP_RECV_CONTENT(); // �ͻ���ֹͣ����

	void onClicked_PB_TCPC_SEND(); // �ͻ��˿�ʼ����

    void doStartLogTcpcConnection(const std::vector<class Connection>& connection); // ��¼������Ϣ

	void onCurrentIndexChanged_CB_TCPC_TARGET_IP(); // Ŀ�� ip �˿ڸ���
	
	void getTcpcRest(const QString & result);  // ��ȡ�ͻ��˽��յķ������Ϣ

	void onCurrentIndexChanged_CB_TCPC_CONNECT_MODE(); // ���ǣ�����ģʽ�任

	void doDisconnectFromServer(); // ���Է����������ӶϿ�

private:
    int currentTCPC() const; // ���ؼ���������ǰ�����

	void isConnect_change_control_status(); // ����״̬�任����

	void recvServerMsg(); // ���շ������Ϣ

private:
    std::vector< TcpClient* > m_tcpc;       // �ͻ��˼���
	class FORM_TCPC_ADD_CONNECT*    m_form_tcpc_add_connect; // �ͻ������ӹ�����
	std::vector<class Connection>   m_tcpcConnection; // �ͻ���������

#pragma endregion
	
};
