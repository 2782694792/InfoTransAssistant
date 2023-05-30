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
#include <qmovie.h> // 显示动态图
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
    bool eventFilter(QObject* obj, QEvent* event) override; // 事件过滤器
    void init_register_eventFilter();
#endif

protected:
    void paintEvent(QPaintEvent* event) override;   // 重新绘画主窗口

    void resizeEvent(QResizeEvent* event) override; // 自适应分辨率大小

private slots:
    void onClickableLabel_Clicked();             // label 点击切换界面
	
private:
    void init_sidebar_label(TextLabelID tlid); // 初始化侧边栏标签
    void clear_sidebar_label(); // 清空侧边栏标签style

    void init_main_slots();
    void init_qss();                        // 初始化按钮圆角
    void init_default_widget();             // 初始化界面效果
    void init_member();                     // 初始化成员变量
    void init_ctrl_visible(bool isVisible); // 初始化控件显示
	
private:
	QWidget * m_parent;
    Ui::ExportScannerInfoClass ui;
    ClickableLabel* label;
	std::valarray<QString> m_mainInfo;
	thread_pool m_pool;

#pragma region TCP 服务端
signals:
    void startGetTcpsLog(); // 开始运行服务端线程以获取返回消息

private slots:
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

    void getTcpsRest(const QString& result); // 获取服务端接收的客户端消息

private:
    void isListen_change_control_status(); // 监听状态更改控件状态

    void prompt_operation_status(
        bool isSuccess, const QString& labelContent) const; // 标签提示操作状态

    int currentTCPS() const; // 返回集合索引当前服务端

	void onUpdateTcpsRecvOrNone(); // 更新服务端是否接收

private:
    std::vector< TcpServer* > m_tcps;       // 服务端集合
    QStringList               m_ClientAddr; // 客户端地址
    QList< int >              m_ClientPort; // 客户端端口
	QString					  m_log; // 接收客户端消息记录
	//QSpacerItem	*			  m_spacerItem; // 空间项
	//QPropertyAnimation *	  m_animation; // 动画类

#pragma endregion

#pragma region TCP 客户端

signals:
	void updateConnectionInfo(const std::vector<class Connection>& connection); // 更新连接信息
	
private slots:
	void onClicked_PB_TCPC_ADD_CONNECT(); // 创建连接

	void onClicked_PB_TCPC_CONNECT(); // 客户端连接

	void onClicked_PB_TCPC_DISCONNECT(); // 客户端断开

	void onClicked_PB_TCPC_START_RECV_CONTENT(); // 客户端开始接收

	void onClicked_PB_TCPC_STOP_RECV_CONTENT(); // 客户端停止接收

	void onClicked_PB_TCPC_SEND(); // 客户端开始发送

    void doStartLogTcpcConnection(const std::vector<class Connection>& connection); // 记录连接信息

	void onCurrentIndexChanged_CB_TCPC_TARGET_IP(); // 目标 ip 端口更改
	
	void getTcpcRest(const QString & result);  // 获取客户端接收的服务端消息

	void onCurrentIndexChanged_CB_TCPC_CONNECT_MODE(); // （非）阻塞模式变换

	void doDisconnectFromServer(); // 来自服务器的连接断开

private:
    int currentTCPC() const; // 返回集合索引当前服务端

	void isConnect_change_control_status(); // 连接状态变换操作

	void recvServerMsg(); // 接收服务端消息

private:
    std::vector< TcpClient* > m_tcpc;       // 客户端集合
	class FORM_TCPC_ADD_CONNECT*    m_form_tcpc_add_connect; // 客户端连接管理窗口
	std::vector<class Connection>   m_tcpcConnection; // 客户端连接类

#pragma endregion
	
};
