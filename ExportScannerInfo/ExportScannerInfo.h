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
    void init_sidebar_label(TextLabelID tlid); // 初始化侧边栏标签
    void clear_sidebar_label();

signals:
    void startGetTcpsLog();

private slots:
    void onClickableLabel_Clicked();             // label 点击切换界面

#pragma region TCPS_SLOTS
	void onClicked_PB_TCPS_LISTEN_PORT_CREATE(); // 端口添加
    void onClicked_PB_TCPS_LISTEN_PORT_DELETE(); // 端口删除
    void onCurrentIndexChanged_CB_TCPS_LISTEN_PORT_LIST(); // 端口切换

    void onClicked_PB_TCPS_LISTENING();                    // 启动端口监听
    void onClicked_PB_TCPS_LISTENED();                     // 停止端口监听

    void onClicked_PB_TCPS_START_RECV_CONTENT(); // 继续接收请求数据
    void onClicked_PB_TCPS_STOP_RECV_CONTENT();  // 暂停接收

    void onUpdateClients(); // 更新客户端信息，禁止获取 socket

    void onCurrentIndexChanged_CB_TCPS_CONNECT_CLIENT_IP(); // 客户端指定信息

	void onStateChanged_CHB_TCPS_ALL_CLIENT(); // 选择所有客户端

	void onClicked_PB_TCPS_DISCONNECT_CLIENT(); // 断开客户端

	void onClicked_PB_TCPS_SEND(); // 发送客户端

    void getTcpsRest(const QString& result);
#pragma endregion

#pragma region TCPC_SLOTS
	void onClicked_PB_TCPC_ADD_CONNECT(); // 创建连接

	void onClicked_PB_TCPC_CONNECT(); // 客户端连接

	void onClicked_PB_TCPC_DISCONNECT(); // 客户端断开

	void onClicked_PB_TCPC_START_RECV_CONTENT(); // 客户端开始接收

	void onClicked_PB_TCPC_STOP_RECV_CONTENT(); // 客户端停止接收

	void onClicked_PB_TCPC_SEND(); // 客户端开始发送

    void doStartLogTcpcConnection(const std::vector<Connection>& connection); // 记录连接信息

#pragma endregion


public:
#ifdef test_eventFilter
    bool eventFilter(QObject* obj, QEvent* event) override; // 事件过滤器
    void init_register_eventFilter();
#endif

private:
    void init_main_slots();
    void init_qss();                        // 初始化按钮圆角
    void init_default_widget();             // 初始化界面效果
    void init_member();                     // 初始化成员变量
    void init_ctrl_visible(bool isVisible); // 初始化控件显示

#ifdef test_ctrl
	void test_ctrl_init();
#endif

    void isListen_change_control_status();

    void prompt_operation_status(
        bool isSuccess, const QString& labelContent) const; // 标签提示操作状态

    int currentTCPS() const; // 返回集合索引当前服务端

	void onUpdateTcpsRecvOrNone(); // 更新服务端是否接收

protected:
    void paintEvent(QPaintEvent* event) override;   // 重新绘画主窗口

    void resizeEvent(QResizeEvent* event) override; // 自适应分辨率大小

private:
    Ui::ExportScannerInfoClass ui;
    std::vector< TcpServer* > m_tcps;       // 服务端集合
    QStringList               m_ClientAddr; // 客户端地址
    QList< int >              m_ClientPort; // 客户端端口
	QString					  m_log;
	QSpacerItem	*			  m_spacerItem;
	QPropertyAnimation *	  m_animation;

	FORM_TCPC_ADD_CONNECT * m_form_tcpc_add_connect;
	std::vector<Connection>   m_tcpcConnection;
};
