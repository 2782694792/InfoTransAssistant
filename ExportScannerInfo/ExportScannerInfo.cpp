#include "ExportScannerInfo.h"
#include <qfile.h>
#include <qmessagebox.h>
#include <thread>

#define cross_thread_start

// #define uncross_thread_start
#ifdef uncross_thread_start
#include <condition_variable>
#include <mutex>
#include "port.h"
bool                    t_canRun = false; // 定义共享数据
std::condition_variable t_cv;
std::mutex              t_mx;
#endif

#pragma region 主程序界面处理

ExportScannerInfo::ExportScannerInfo(QWidget* parent) : QMainWindow(parent) {
	ui.setupUi(this);

	init_main_slots();
	init_default_widget();
	init_ctrl_visible(false);
	init_member();

#ifdef test_ctrl
	test_ctrl_init();
#endif

#ifdef test_eventFilter
	init_register_eventFilter();
#endif
}

void ExportScannerInfo::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);
	painter.fillRect(rect(), QColor("#F5F5F5"));
}

void ExportScannerInfo::resizeEvent(QResizeEvent* event) {
	// int w = event->size().width();
	// int h = event->size().height();
	// this->resize(w * 0.8, h * 0.8);
	// this->move(w * 0.1, h * 0.1);
}

void ExportScannerInfo::init_main_slots() {
	connect(ui.TL_FTP_SERVER, SIGNAL(clicked()), this,
		SLOT(onClickableLabel_Clicked()));
	connect(ui.TL_FTP_CLIENT, SIGNAL(clicked()), this,
		SLOT(onClickableLabel_Clicked()));
	connect(ui.TL_TCP_SERVER, SIGNAL(clicked()), this,
		SLOT(onClickableLabel_Clicked()));
	connect(ui.TL_TCP_CLIENT, SIGNAL(clicked()), this,
		SLOT(onClickableLabel_Clicked()));
	connect(ui.TL_PDF_EXPORT, SIGNAL(clicked()), this,
		SLOT(onClickableLabel_Clicked()));

	connect(ui.TL_PDF_ICON, SIGNAL(clicked()), this,
		SLOT(onClickableLabel_Clicked()));
	connect(ui.TL_TCP, SIGNAL(clicked()), this,
		SLOT(onClickableLabel_Clicked()));
}

void ExportScannerInfo::init_default_widget() {
	emit ui.TL_TCP_SERVER->clicked();

	// setWindowFlags(Qt::FramelessWindowHint);	// 设置窗口无边框
	setAttribute(Qt::WA_TranslucentBackground); // 设置窗口透明度
	setWindowOpacity(0.96);
	// setAttribute(Qt::WA_TransparentForMouseEvents);	// 设置标题栏隐藏

	init_qss();
}

void ExportScannerInfo::init_qss() {
	QFile styleFile("./main.qss");
	styleFile.open(QFile::ReadOnly | QFile::Text);
	QString style = QString(styleFile.readAll().data());
	qApp->setStyleSheet(style.toLocal8Bit());
}

void ExportScannerInfo::init_ctrl_visible(bool isVisible) {
	ui.TL_FTP->setVisible(isVisible);
	ui.TL_FTP_CLIENT->setVisible(isVisible);
	ui.TL_FTP_SERVER->setVisible(isVisible);

	ui.PB_TCPS_START_RECV_CONTENT->setEnabled(isVisible);
	ui.PB_TCPS_STOP_RECV_CONTENT->setEnabled(isVisible);

	// 添加QSpacerItem到垂直布局中，用于占据空间
	m_spacerItem = new QSpacerItem(0, 0, QSizePolicy::Preferred, QSizePolicy::Expanding);
	ui.VLAYOUT_PDF_SETS->addItem(m_spacerItem);
}

void ExportScannerInfo::clear_sidebar_label() {
	QString  strColor = QString::fromLocal8Bit("color:balck;");
	QPalette label_palette;

	ui.TL_FTP_SERVER->setStyleSheet(strColor);
	ui.TL_FTP_SERVER->setPalette(label_palette);
	ui.TL_FTP_SERVER_ICON->setStyleSheet("");

	ui.TL_FTP_CLIENT->setStyleSheet(strColor);
	ui.TL_FTP_CLIENT->setPalette(label_palette);
	ui.TL_FTP_CLIENT_ICON->setStyleSheet("");

	ui.TL_TCP_SERVER->setStyleSheet(strColor);
	ui.TL_TCP_SERVER->setPalette(label_palette);
	ui.TL_TCP_SERVER_ICON->setStyleSheet("");

	ui.TL_TCP_CLIENT->setStyleSheet(strColor);
	ui.TL_TCP_CLIENT->setPalette(label_palette);
	ui.TL_TCP_CLIENT_ICON->setStyleSheet("");

	ui.TL_PDF_EXPORT->setStyleSheet(strColor);
	ui.TL_PDF_EXPORT->setPalette(label_palette);
	ui.TL_PDF_EXPORT_ICON->setStyleSheet("");
}

void ExportScannerInfo::init_sidebar_label(TextLabelID tlid) {
	clear_sidebar_label();

	auto          label = ui.TL_FTP_SERVER;
	const QString font = QString::fromLocal8Bit(
		"color:white; font-size: 20px;font-weight: bold;");
	const QString border = QString::fromLocal8Bit("border-radius:13px;");

	QString label_style = QString::fromLocal8Bit(
		"background-color: rgb(59, 154, 253);" + (font + border).toLocal8Bit());

	auto    label_icon = ui.TL_FTP_SERVER_ICON;
	QString label_icon_style = QString::fromLocal8Bit(
		"border-image:url(\"./images/toRight-blue.png\");");

	switch (tlid) {
	case FTP_SERVER:
		label = ui.TL_FTP_SERVER;
		label_icon = ui.TL_FTP_SERVER_ICON;
		break;
	case FTP_CLIENT:
		label = ui.TL_FTP_CLIENT;
		label_icon = ui.TL_FTP_CLIENT_ICON;
		break;
	case TCP_SERVER:
		label = ui.TL_TCP_SERVER;
		label_icon = ui.TL_TCP_SERVER_ICON;
		break;
	case TCP_CLIENT:
		label = ui.TL_TCP_CLIENT;
		label_icon = ui.TL_TCP_CLIENT_ICON;
		break;
	case PDF_EXPORT:
		label = ui.TL_PDF_EXPORT;
		label_style =
			QString::fromLocal8Bit("background-color: rgb(16, 168, 101);"
			+ (font + border).toLocal8Bit());

		label_icon = ui.TL_PDF_EXPORT_ICON;
		label_icon_style = QString::fromLocal8Bit(
			"border-image:url(\"./images/toRight.png\");");
		break;
	case UNKNOWN:
		return;
	default:
		break;
	}

	label->setStyleSheet(label_style);
	label_icon->setStyleSheet(label_icon_style);
}

void ExportScannerInfo::init_member() {
	label = new ClickableLabel();
}

void ExportScannerInfo::onClickableLabel_Clicked() {
	TextLabelID tempID = TextLabelID::UNKNOWN;

	auto* label = static_cast<ClickableLabel*>(sender());
	if (label == ui.TL_TCP_SERVER) {
		ui.STACKWIDGET->setCurrentIndex(tempID = TextLabelID::TCP_SERVER);
	}
	else if (label == ui.TL_TCP_CLIENT) {
		ui.STACKWIDGET->setCurrentIndex(tempID = TextLabelID::TCP_CLIENT);
	}
	else if (label == ui.TL_PDF_EXPORT) {
		ui.STACKWIDGET->setCurrentIndex(tempID = TextLabelID::PDF_EXPORT);
	}
#ifdef test_ftp
	else if (label == ui.TL_FTP_SERVER) {
		ui.STACKWIDGET->setCurrentIndex(
			TextLabelID::FTP_SERVER); // 根据触发的按钮来进行所要显示的QWidget
	}
	else if (label == ui.TL_FTP_CLIENT) {
		ui.STACKWIDGET->setCurrentIndex(TextLabelID::FTP_CLIENT);
	}
#endif
	else if (label == ui.TL_PDF_ICON){
		//QPropertyAnimation *animation = new QPropertyAnimation(ui.GB_PDF_SETS, "maximumHeight");
		if (ui.GB_PDF_SETS->isVisible()) {
			//if (ui.GB_PDF_SETS->maximumHeight() > 0) {
			//animation->setStartValue(ui.GB_PDF_SETS->maximumHeight());
			//animation->setEndValue(0);
			//animation->setDuration(300);
			//animation->start();
			//m_spacerItem->changeSize(0, 0, QSizePolicy::Preferred, QSizePolicy::Expanding);
			ui.GB_PDF_SETS->setVisible(false);
		}
		else {
			//animation->setStartValue(0);
			//animation->setEndValue(ui.GB_PDF_SETS->minimumHeight());
			//animation->setDuration(300);
			//animation->start();
			//m_spacerItem->changeSize(0, ui.GB_PDF_SETS->minimumHeight(), QSizePolicy::Preferred, QSizePolicy::Expanding);
			ui.GB_PDF_SETS->setVisible(true);
		}
	}
	else if (label == ui.TL_TCP)
	{
		if (ui.GB_TCP_SETS->isVisible()) {
			ui.GB_TCP_SETS->setVisible(false);
		}
		else {
			ui.GB_TCP_SETS->setVisible(true);
		}
	}
	else
	{

	}

	init_sidebar_label(tempID);
}

#pragma endregion

#pragma region TCP 服务端连接处理

#ifdef test_eventFilter

void ExportScannerInfo::init_register_eventFilter() {
	// ui.TL_FTP_SERVER->installEventFilter(this);
	// ui.TL_FTP_CLIENT->installEventFilter(this);
	// ui.TL_TCP_SERVER->installEventFilter(this);
	// ui.TL_TCP_CLIENT->installEventFilter(this);
	ui.TL_PDF_EXPORT->installEventFilter(this);
}

bool ExportScannerInfo::eventFilter(QObject* obj, QEvent* event) {
	if (obj == ui.TL_FTP_SERVER) {
		// enum_textLabelClick = TextLabelID::FTP_SERVER;
		return true;
	}
	else {
		return false;
	}

	// if (event->type() == QEvent::MouseButtonPress)
	//{
	// QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
	// if (mouseEvent->button() == Qt::LeftButton)
	//{
	//	emit label->clicked();
	//	return true;
	// }
	// }
	// else
	//{
	//	return false;
	// }

	return QObject::eventFilter(obj, event);
}
#endif

// 添加端口号到 CB 中
void ExportScannerInfo::onClicked_PB_TCPS_LISTEN_PORT_CREATE() {
	std::string tempstr = std::string(TPStr.PORT_ILLEGAL);
	bool        isCreate = false;

	if (IpPort.isValidPort(ui.LE_TCPS_LISTEN_PORT->text().toInt())) {
		QString text = ui.LE_TCPS_LISTEN_PORT->text();

		int i = 0;
		for each (auto var in m_tcps) {
			if (var->m_port == text.toInt()) {
				i++;
			}
		}

		if (i == 0) {
			TcpServer* tcps = new TcpServer(text.toInt()); // 启动 tcp 线程
			m_tcps.push_back(tcps);

			ui.CB_TCPS_LISTEN_PORT_LIST->addItem(text);
			tempstr = text.toStdString() + " "
				+ std::string(TPStr.PORT_ADDING_SUCCESS);
			isCreate = true;
			ui.LE_TCPS_LISTEN_PORT->clear();

			int lastIndex = ui.CB_TCPS_LISTEN_PORT_LIST->count() - 1;
			ui.CB_TCPS_LISTEN_PORT_LIST->setCurrentIndex(lastIndex);

			int temp = currentTCPS();
			connect(m_tcps[temp], &TcpServer::updateClientsReady, this,
				&ExportScannerInfo::onUpdateClients);
			connect(this, SIGNAL(startGetTcpsLog()), m_tcps[temp],
				SLOT(start()));
			connect(m_tcps[temp], &TcpServer::logReady, this,
				&ExportScannerInfo::getTcpsRest);
		}
		else {
			tempstr = std::string(TPStr.PORT_ADDED);
		}
	}

	if (isCreate) {
		LOGI_(tempstr.data());
	}
	else {
		LOGE_(tempstr.data());
	}

	prompt_operation_status(isCreate, tempstr);
}

// 删除端口
void ExportScannerInfo::onClicked_PB_TCPS_LISTEN_PORT_DELETE() {
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

#ifdef cross_thread_start
	if (!m_tcps[temp]->isRunning()) {
		return;
	}

	m_tcps[temp]->terminate();

	if (m_tcps[temp]->isListen())
	{
		listenNum--;
	}
	m_tcps[temp]->wait();
	m_tcps[temp]->closeServer();
#endif
	
	isListen_change_control_status();

	prompt_operation_status(false, m_tcps[temp]->m_port + " 已删除端口号");

	auto i = m_tcps.begin();
	i += temp;
	m_tcps.erase(i);

	int     lastIndex = ui.CB_TCPS_LISTEN_PORT_LIST->currentIndex();
	ui.CB_TCPS_LISTEN_PORT_LIST->removeItem(lastIndex); // 删除当前选择的item

	onUpdateClients();
}

// 切换 combobox 选择更改本地端口标签
void ExportScannerInfo::onCurrentIndexChanged_CB_TCPS_LISTEN_PORT_LIST() {
	ui.TL_TCPS_LOCAL_PORT->setText(ui.CB_TCPS_LISTEN_PORT_LIST->currentText());

	if (ui.CB_TCPS_LISTEN_PORT_LIST->count() > 0) {
		isListen_change_control_status();
	}

	onUpdateClients();
	onUpdateTcpsRecvOrNone();
}

// 开始监听
void ExportScannerInfo::onClicked_PB_TCPS_LISTENING() {
	/// 1 非法监听
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	/// 2 开始监听
#ifdef cross_thread_start
	//emit startGetTcpsLog();
	m_tcps[temp]->start();
	m_tcps[temp]->setPriority(QThread::LowPriority);
#endif

	/// 3 避免重复监听
	if (m_tcps[temp]->getStatus() != TP::LISTENING) {
		m_tcps[temp]->startListen();
		listenNum += 1; // 更改监听数
	}

	/// 4 更改监听状态
	isListen_change_control_status();

	LOGI_("");

#ifdef uncross_thread_start
	// 启动线程读数据，不可跨线程通信
	t_canRun = true;
	// std::thread	t_tcpsRest(&ExportScannerInfo::getTcpsRest, this);
	std::thread t_tcpsRest([&]() {
		LOGI_("发出信号 startGetTcpsLog");
		emit startGetTcpsLog();
	});
	t_tcpsRest.detach();
#endif
}

// 监听状态改变控件状态
void ExportScannerInfo::isListen_change_control_status() {
	int  index = currentTCPS();
	bool inListen = m_tcps[index]->isListen();
	if (inListen) // 可由服务端获取监听状态
	{
		ui.TE_TCPS_RECV_CONTENT->setFocus();
		prompt_operation_status(inListen, TPStr.LISTENING);
	}
	else // 未监听
	{
		ui.TL_PROMPT_OPERATION_STATUS->setFocus();
		prompt_operation_status(!inListen, TPStr.NOT_LISTENED);
	}

	ui.PB_TCPS_START_RECV_CONTENT->setEnabled(!inListen);
	ui.PB_TCPS_LISTENING->setEnabled(!inListen);
	ui.PB_TCPS_STOP_RECV_CONTENT->setEnabled(inListen);

	ui.TL_TCPS_LISTEN_COUNT->setText(QString::number(listenNum));
}

// 停止监听
void ExportScannerInfo::onClicked_PB_TCPS_LISTENED() {
	/// 1 非法停止
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	/// 2 避免重复停止
	if (m_tcps[temp]->getStatus() == TP::NOT_LISTENED) {
		prompt_operation_status(false, TPStr.NOT_LISTENED);
		return;
	}

#ifdef cross_thread_start
	if (m_tcps[temp]->isRunning()) {
		/// 3 停止监听
		m_tcps[temp]->stopListen();
		listenNum -= 1;
		isListen_change_control_status();

		/// 4 关闭线程
		m_tcps[temp]->terminate();
		m_tcps[temp]->wait();
		//m_tcps[temp]->exit();
	}
#endif

#ifdef uncross_thread_start
	{
		std::lock_guard< std::mutex > lk(t_mx);
		t_canRun = false;
		LOGI("Stop Listen\n");
	}
	t_cv.notify_all(); // 通知其他线程
#endif

	LOGE_("");
}

// 继续接收请求数据
void ExportScannerInfo::onClicked_PB_TCPS_START_RECV_CONTENT() {
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	m_tcps[temp]->startRecvRequestData();
	onUpdateTcpsRecvOrNone();

	LOGI_("");
}

// 停止接收
void ExportScannerInfo::onClicked_PB_TCPS_STOP_RECV_CONTENT() {
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	m_tcps[temp]->stopRecvRequestData();
	onUpdateTcpsRecvOrNone();

	LOGE_("");
}

// 更改指定客户端
void ExportScannerInfo::onCurrentIndexChanged_CB_TCPS_CONNECT_CLIENT_IP() {
	QString ip = ui.CB_TCPS_CONNECT_CLIENT_IP->currentText();

	int i = 0;
	for each (auto var in m_ClientAddr) {
		if (var == ip) {
			ui.LE_TCPS_CONTENT_CLIENT_PORT->setText(
				QString::number(m_ClientPort[i]));
		}
		i++;
	}
}

// 选择所有客户端
void ExportScannerInfo::onStateChanged_CHB_TCPS_ALL_CLIENT(){
	ui.CB_TCPS_CONNECT_CLIENT_IP->setEnabled(true);

	if (ui.CHB_TCPS_ALL_CLIENT->isChecked()) // 所有
	{
		ui.CB_TCPS_CONNECT_CLIENT_IP->setEnabled(false);
	}
}

// 断开客户端
void ExportScannerInfo::onClicked_PB_TCPS_DISCONNECT_CLIENT(){
	int temp = currentTCPS();
	if (temp < 0) { // 无服务端
		return;
	}
	if (m_tcps[temp]->getClientsCount() <= 0) // 无客户端
	{
		return;
	}

	if (ui.CHB_TCPS_ALL_CLIENT->isChecked()) // 所有
	{
		m_tcps[temp]->disconnectedAll();
	}
	else
	{
		m_tcps[temp]->disconnectedOne(ui.CB_TCPS_CONNECT_CLIENT_IP->currentText(), ui.LE_TCPS_CONTENT_CLIENT_PORT->text().toInt());
	}

	LOGI_("");
}

// 指定发送
void ExportScannerInfo::onClicked_PB_TCPS_SEND(){
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}
	if (m_tcps[temp]->getClientsCount() <= 0)
	{
		return;
	}

	TP isSuccess = TP::SEND_FAILURE;
	QString mess = "";

	if (ui.CHB_TCPS_ALL_CLIENT->isChecked()) // 所有
	{
		int num = ui.SB_TCPS_NUM_SEND->text().toInt();
		mess = ui.TE_TCPS_SEND_CONTENT->toPlainText();

		isSuccess = m_tcps[temp]->sendDataToClient(num, mess.toStdString().data());
	}
	else // 指定客户端
	{
		QString ip = ui.CB_TCPS_CONNECT_CLIENT_IP->currentText();
		int port = ui.LE_TCPS_CONTENT_CLIENT_PORT->text().toInt();
		int num = ui.SB_TCPS_NUM_SEND->text().toInt();
		mess = ui.TE_TCPS_SEND_CONTENT->toPlainText();

		isSuccess = m_tcps[temp]->sendDataToClient(ip, port, num, mess.toStdString().data());
	}

	prompt_operation_status(isSuccess == TP::SEND_SUCCESS, (isSuccess == TP::SEND_SUCCESS ? TPStr.SEND_SUCCESS : TPStr.SEND_FAILURE));

	LOGI_("");
}

// 当前监听的服务端端口
int ExportScannerInfo::currentTCPS() const {
	QString text = ui.CB_TCPS_LISTEN_PORT_LIST->currentText();
	if (text.isEmpty()) {
		return -1;
	}

	TcpServer tcps;

	int i = 0;
	for each (auto var in m_tcps) {
		if (var->m_port == text.toInt()) {
			return i;
		}
		i++;
	}

	prompt_operation_status(false,
		TPStr.PORT_ILLEGAL);
	LOGE_(std::string(TPStr.PORT_ILLEGAL));

	return -1;
}

// 信号槽(线程)获取tcp服务器接收的数据
void ExportScannerInfo::getTcpsRest(const QString& result) {
#ifdef uncross_thread_start
	std::unique_lock< std::mutex > lk(t_mx);
	while (!t_canRun) {
		t_cv.wait(lk);
	}
#endif

	if (!result.isEmpty()) {
		// std::this_thread::sleep_for(std::chrono::seconds(1)); // 停顿1秒钟
		LOGI_(result.toStdString().data());
		ui.TE_TCPS_RECV_CONTENT->append(result.toStdString().data());
		prompt_operation_status(true, "");

		m_log = result;
	}
	else {
		prompt_operation_status(false, "接收为空");
		LOGE_("");
	}

#ifdef uncross_thread_start
	lk.unlock();
#endif
}

// 客户端信息更新
void ExportScannerInfo::onUpdateClients() {
	ui.CB_TCPS_CONNECT_CLIENT_IP->clear();
	ui.LE_TCPS_CONTENT_CLIENT_PORT->clear();

	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	// 1. 更新客户端信息
	m_tcps[temp]->getClientsInfo(m_ClientAddr, m_ClientPort);
	int i = 0;

	for each (auto var in m_ClientAddr) {
		int port = m_ClientPort[i];
		LOGI("%s: %d", var.toStdString().data(), port);
		i++;

		ui.CB_TCPS_CONNECT_CLIENT_IP->addItem(var);
	}

	// 2. 更新客户端连接数量
	ui.TL_TCPS_CLIENT_COUNT->setText(
		QString::number(m_tcps[temp]->getClientsCount()));
}

// 更新客户端请求数据的接收状态
void ExportScannerInfo::onUpdateTcpsRecvOrNone(){
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	if (m_tcps[temp]->getStatus() == TP::RECVING_REQUEST_DATA)
	{
		ui.PB_TCPS_START_RECV_CONTENT->setEnabled(false);
		ui.PB_TCPS_STOP_RECV_CONTENT->setEnabled(true);
		prompt_operation_status(true, TPStr.RECVING_REQUEST_DATA);
	}

	if (m_tcps[temp]->getStatus() == TP::STOP_RECVED_REQUEST_DATA)
	{
		ui.PB_TCPS_START_RECV_CONTENT->setEnabled(true);
		ui.PB_TCPS_STOP_RECV_CONTENT->setEnabled(false);
		prompt_operation_status(false, TPStr.STOP_RECVED_REQUEST_DATA);
	}
}

// 标签提示操作状态
void ExportScannerInfo::prompt_operation_status(
	bool isSuccess, const std::string & labelContent) const {
	ui.TL_PROMPT_OPERATION_STATUS->setText(labelContent.data()); // 设置文本
	ui.TL_PROMPT_OPERATION_STATUS->setAlignment(
		Qt::AlignCenter); // 设置文本对齐方式为居中
	QColor   color = isSuccess ? QColor(Qt::blue)
		: QColor(Qt::red); // 根据success参数设置文本颜色
	QPalette palette;
	palette.setColor(QPalette::WindowText, color);
	ui.TL_PROMPT_OPERATION_STATUS->setPalette(palette);
}

#pragma endregion

#pragma region TCP 客户端连接处理

void ExportScannerInfo::onClicked_PB_TCPC_ADD_CONNECT(){
	m_form_tcpc_add_connect = new FORM_TCPC_ADD_CONNECT;

	connect(m_form_tcpc_add_connect, &FORM_TCPC_ADD_CONNECT::startLogTcpcConnection, this,
		&ExportScannerInfo::doStartLogTcpcConnection);

	m_form_tcpc_add_connect->setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint);
	m_form_tcpc_add_connect->setModal(true);

	m_form_tcpc_add_connect->show();
	m_form_tcpc_add_connect->exec();
}

void ExportScannerInfo::doStartLogTcpcConnection(const std::vector<Connection>& connection){
	if (connection.size() > 0)
	{
		ui.CB_TCPC_TARGET_IP->clear();
		ui.CB_TCPC_TARGET_PORT->clear();

		for (auto var : connection)
		{
			ui.CB_TCPC_TARGET_IP->addItem(var.getIP());
			ui.CB_TCPC_TARGET_PORT->addItem(QString::number(var.getPort()));
		}

		int lastIndex = ui.CB_TCPC_TARGET_IP->count() - 1;
		ui.CB_TCPC_TARGET_IP->setCurrentIndex(lastIndex);
		lastIndex = ui.CB_TCPC_TARGET_PORT->count() - 1;
		ui.CB_TCPC_TARGET_PORT->setCurrentIndex(lastIndex);
	}

	m_form_tcpc_add_connect = nullptr;
}


void ExportScannerInfo::onClicked_PB_TCPC_CONNECT(){

}

void ExportScannerInfo::onClicked_PB_TCPC_DISCONNECT(){

}

void ExportScannerInfo::onClicked_PB_TCPC_START_RECV_CONTENT(){

}

void ExportScannerInfo::onClicked_PB_TCPC_STOP_RECV_CONTENT(){

}

void ExportScannerInfo::onClicked_PB_TCPC_SEND(){

}

#pragma endregion
