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
bool                    t_canRun = false; // ���干������
std::condition_variable t_cv;
std::mutex              t_mx;
#endif

#pragma region ��������洦��

ExportScannerInfo::ExportScannerInfo(QWidget* parent) : QMainWindow(parent) {
	ui.setupUi(this);

	init_main_slots();
	init_default_widget();
	init_ctrl_visible(false);
	init_member();

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

	// setWindowFlags(Qt::FramelessWindowHint);	// ���ô����ޱ߿�
	setAttribute(Qt::WA_TranslucentBackground); // ���ô���͸����
	setWindowOpacity(0.96);
	// setAttribute(Qt::WA_TransparentForMouseEvents);	// ���ñ���������

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

	// ���QSpacerItem����ֱ�����У�����ռ�ݿռ�
	//m_spacerItem = new QSpacerItem(0, 0, QSizePolicy::Preferred, QSizePolicy::Expanding);
	//ui.VLAYOUT_PDF_SETS->addItem(m_spacerItem);
}

void ExportScannerInfo::clear_sidebar_label() {
	QString  strColor = QString::fromLocal8Bit("color:balck;");
	QPalette label_palette;

	ui.TL_FTP_SERVER->setStyleSheet(strColor);
	ui.TL_FTP_SERVER->setPalette(label_palette);
	ui.TL_FTP_SERVER_ICON->setStyleSheet("QLabel:hover {color: #2980B9;}");

	ui.TL_FTP_CLIENT->setStyleSheet(strColor);
	ui.TL_FTP_CLIENT->setPalette(label_palette);
	ui.TL_FTP_CLIENT_ICON->setStyleSheet("QLabel:hover {color: #2980B9;}");

	ui.TL_TCP_SERVER->setStyleSheet(strColor);
	ui.TL_TCP_SERVER->setPalette(label_palette);
	ui.TL_TCP_SERVER_ICON->setStyleSheet("QLabel:hover {color: #2980B9;}");

	ui.TL_TCP_CLIENT->setStyleSheet(strColor);
	ui.TL_TCP_CLIENT->setPalette(label_palette);
	ui.TL_TCP_CLIENT_ICON->setStyleSheet("QLabel:hover {color: #2980B9;}");

	ui.TL_PDF_EXPORT->setStyleSheet(strColor);
	ui.TL_PDF_EXPORT->setPalette(label_palette);
	ui.TL_PDF_EXPORT_ICON->setStyleSheet("QLabel:hover {color: #2980B9;}");
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

	m_mainInfo[0] = "";
	m_mainInfo[1] = "";
	m_mainInfo[2] = "";
	m_mainInfo[3] = "";
	m_mainInfo[4] = "";
	m_mainInfo[5] = "";

	m_form_tcpc_add_connect = new FORM_TCPC_ADD_CONNECT(this);
	m_form_tcpc_add_connect->hide();

	connect(m_form_tcpc_add_connect, &FORM_TCPC_ADD_CONNECT::startLogTcpcConnection, this,
		&ExportScannerInfo::doStartLogTcpcConnection);
	connect(this, &ExportScannerInfo::updateConnectionInfo, m_form_tcpc_add_connect, &FORM_TCPC_ADD_CONNECT::doUpdateConnectionInfo);
}

void ExportScannerInfo::onClickableLabel_Clicked() {
	TextLabelID tempID = TextLabelID::UNKNOWN;

	int i = ui.STACKWIDGET->currentIndex(); // 0 tcps 1 tcpc 2 pdfexport
	QString info = ui.TL_PROMPT_OPERATION_STATUS->text();
	m_mainInfo[i] = info;

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
			TextLabelID::FTP_SERVER); // ���ݴ����İ�ť��������Ҫ��ʾ��QWidget
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

	i = ui.STACKWIDGET->currentIndex();
	prompt_operation_status(false, m_mainInfo[i]);

	init_sidebar_label(tempID);
}

#pragma endregion

#pragma region TCP ��������Ӵ���

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

// ��Ӷ˿ںŵ� CB ��
void ExportScannerInfo::onClicked_PB_TCPS_LISTEN_PORT_CREATE() {
	std::string tempstr = TPStr.PORT_ILLEGAL.toStdString();
	bool        isCreate = false;

	if (TCPCheck.isValidPort(ui.LE_TCPS_LISTEN_PORT->text().toInt())) {
		QString text = ui.LE_TCPS_LISTEN_PORT->text();

		int i = 0;
		for each (auto var in m_tcps) {
			if (var->m_port == text.toInt()) {
				i++;
			}
		}

		if (i == 0) {
			TcpServer* tcps = new TcpServer(text.toInt()); // ���� tcp �߳�
			m_tcps.push_back(tcps);

			ui.CB_TCPS_LISTEN_PORT_LIST->addItem(text);
			tempstr = text.toStdString() + " "
				+ TPStr.PORT_ADDING_SUCCESS.toStdString();
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
			tempstr = TPStr.PORT_ADDED.toStdString();
		}
	}

	if (isCreate) {
		LOGI_(tempstr.data());
	}
	else {
		LOGE_(tempstr.data());
	}

	prompt_operation_status(isCreate, tempstr.data());
}

// ɾ���˿�
void ExportScannerInfo::onClicked_PB_TCPS_LISTEN_PORT_DELETE() {
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

#ifdef cross_thread_start
	if (!m_tcps[temp]->isRunning()) {
		{
			auto i = m_tcps.begin();
			i += temp;
			m_tcps.erase(i);

			int     lastIndex = ui.CB_TCPS_LISTEN_PORT_LIST->currentIndex();
			ui.CB_TCPS_LISTEN_PORT_LIST->removeItem(lastIndex); // ɾ����ǰѡ���item
		}
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

	prompt_operation_status(false, QString::number(m_tcps[temp]->m_port) + QString::fromLocal8Bit(std::string(" ��ɾ���˿ں�").data()));

	auto i = m_tcps.begin();
	i += temp;
	m_tcps.erase(i);

	int     lastIndex = ui.CB_TCPS_LISTEN_PORT_LIST->currentIndex();
	ui.CB_TCPS_LISTEN_PORT_LIST->removeItem(lastIndex); // ɾ����ǰѡ���item

	onUpdateClients();
}

// �л� combobox ѡ����ı��ض˿ڱ�ǩ
void ExportScannerInfo::onCurrentIndexChanged_CB_TCPS_LISTEN_PORT_LIST() {
	ui.TL_TCPS_LOCAL_PORT->setText(ui.CB_TCPS_LISTEN_PORT_LIST->currentText());

	if (ui.CB_TCPS_LISTEN_PORT_LIST->count() > 0) {
		isListen_change_control_status();
	}

	onUpdateClients();
	onUpdateTcpsRecvOrNone();
}

// ��ʼ����
void ExportScannerInfo::onClicked_PB_TCPS_LISTENING() {
	/// 1 �Ƿ�����
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	/// 2 ��ʼ����
#ifdef cross_thread_start
	//emit startGetTcpsLog();
	m_tcps[temp]->start();
	m_tcps[temp]->setPriority(QThread::LowPriority);
#endif

	/// 3 �����ظ�����
	if (m_tcps[temp]->getStatus() != TP::LISTENING) {
		m_tcps[temp]->startListen();
		listenNum += 1; // ���ļ�����
	}

	/// 4 ���ļ���״̬
	isListen_change_control_status();

	LOGI_("");

#ifdef uncross_thread_start
	// �����̶߳����ݣ����ɿ��߳�ͨ��
	t_canRun = true;
	// std::thread	t_tcpsRest(&ExportScannerInfo::getTcpsRest, this);
	std::thread t_tcpsRest([&]() {
		LOGI_("�����ź� startGetTcpsLog");
		emit startGetTcpsLog();
	});
	t_tcpsRest.detach();
#endif
}

// ����״̬�ı�ؼ�״̬
void ExportScannerInfo::isListen_change_control_status() {
	int  index = currentTCPS();
	bool inListen = m_tcps[index]->isListen();
	if (inListen) // ���ɷ���˻�ȡ����״̬
	{
		ui.TE_TCPS_RECV_CONTENT->setFocus();
		prompt_operation_status(inListen, TPStr.LISTENING);
	}
	else // δ����
	{
		ui.TL_PROMPT_OPERATION_STATUS->setFocus();
		prompt_operation_status(!inListen, TPStr.NOT_LISTENED);
	}

	ui.PB_TCPS_START_RECV_CONTENT->setEnabled(!inListen);
	ui.PB_TCPS_LISTENING->setEnabled(!inListen);
	ui.PB_TCPS_STOP_RECV_CONTENT->setEnabled(inListen);

	ui.TL_TCPS_LISTEN_COUNT->setText(QString::number(listenNum));
}

// ֹͣ����
void ExportScannerInfo::onClicked_PB_TCPS_LISTENED() {
	/// 1 �Ƿ�ֹͣ
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	/// 2 �����ظ�ֹͣ
	if (m_tcps[temp]->getStatus() == TP::NOT_LISTENED) {
		prompt_operation_status(false, TPStr.NOT_LISTENED);
		return;
	}

#ifdef cross_thread_start
	if (m_tcps[temp]->isRunning()) {
		/// 3 ֹͣ����
		m_tcps[temp]->stopListen();
		listenNum -= 1;
		isListen_change_control_status();

		/// 4 �ر��߳�
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
	t_cv.notify_all(); // ֪ͨ�����߳�
#endif

	LOGE_(TPStr.NOT_LISTENED.toStdString().data());
}

// ����������������
void ExportScannerInfo::onClicked_PB_TCPS_START_RECV_CONTENT() {
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	m_tcps[temp]->startRecvRequestData();
	onUpdateTcpsRecvOrNone();

	//connect(m_tcps[temp], &TcpServer::logReady, this,	&ExportScannerInfo::getTcpsRest);

	LOGI_(TPStr.RECVING_REQUEST_DATA);
}

// ֹͣ����
void ExportScannerInfo::onClicked_PB_TCPS_STOP_RECV_CONTENT() {
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	m_tcps[temp]->stopRecvRequestData();
	onUpdateTcpsRecvOrNone();
	
	//disconnect(m_tcps[temp], &TcpServer::logReady, this,	&ExportScannerInfo::getTcpsRest);

	LOGE_(TPStr.STOP_RECVED_REQUEST_DATA);
}

// ����ָ���ͻ���
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

// ѡ�����пͻ���
void ExportScannerInfo::onStateChanged_CHB_TCPS_ALL_CLIENT(){
	ui.CB_TCPS_CONNECT_CLIENT_IP->setEnabled(true);

	if (ui.CHB_TCPS_ALL_CLIENT->isChecked()) // ����
	{
		ui.CB_TCPS_CONNECT_CLIENT_IP->setEnabled(false);
	}
}

// �Ͽ��ͻ���
void ExportScannerInfo::onClicked_PB_TCPS_DISCONNECT_CLIENT(){
	int temp = currentTCPS();
	if (temp < 0) { // �޷����
		return;
	}
	if (m_tcps[temp]->getClientsCount() <= 0) // �޿ͻ���
	{
		return;
	}

	if (ui.CHB_TCPS_ALL_CLIENT->isChecked()) // ����
	{
		m_tcps[temp]->disconnectedAll();
	}
	else
	{
		m_tcps[temp]->disconnectedOne(ui.CB_TCPS_CONNECT_CLIENT_IP->currentText(), ui.LE_TCPS_CONTENT_CLIENT_PORT->text().toInt());
	}

	LOGI_(TPStr.DISCONNECT.toStdString().data());
}

// ָ������
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

	if (ui.CHB_TCPS_ALL_CLIENT->isChecked()) // ����
	{
		int num = ui.SB_TCPS_NUM_SEND->text().toInt();
		mess = ui.TE_TCPS_SEND_CONTENT->toPlainText();

		isSuccess = m_tcps[temp]->sendDataToClient(num, mess.toStdString().data());
	}
	else // ָ���ͻ���
	{
		QString ip = ui.CB_TCPS_CONNECT_CLIENT_IP->currentText();
		int port = ui.LE_TCPS_CONTENT_CLIENT_PORT->text().toInt();
		int num = ui.SB_TCPS_NUM_SEND->text().toInt();
		mess = ui.TE_TCPS_SEND_CONTENT->toPlainText();

		isSuccess = m_tcps[temp]->sendDataToClient(ip, port, num, mess.toStdString().data());
	}

	prompt_operation_status(isSuccess == TP::SEND_SUCCESS, (isSuccess == TP::SEND_SUCCESS ? TPStr.SEND_SUCCESS : TPStr.SEND_FAILURE).toStdString().data());

	LOGI_("");
}

// ��ǰ�����ķ���˶˿�
int ExportScannerInfo::currentTCPS() const {
	QString text = ui.CB_TCPS_LISTEN_PORT_LIST->currentText();
	if (text.isEmpty()) {
		return -1;
	}

	int i = 0;
	for each (auto var in m_tcps) {
		if (var->m_port == text.toInt()) {
			return i;
		}
		i++;
	}

	prompt_operation_status(false,
		TPStr.PORT_ILLEGAL.toStdString().data());
	LOGE_(TPStr.PORT_ILLEGAL.toStdString().data());

	return -1;
}

// �źŲ�(�߳�)��ȡtcp���������յ�����
void ExportScannerInfo::getTcpsRest(const QString& result) {
#ifdef uncross_thread_start
	std::unique_lock< std::mutex > lk(t_mx);
	while (!t_canRun) {
		t_cv.wait(lk);
	}
#endif

	if (!result.isEmpty()) {
		// std::this_thread::sleep_for(std::chrono::seconds(1)); // ͣ��1����
		LOGI_(result.toStdString().data());
		ui.TE_TCPS_RECV_CONTENT->append(result.toStdString().data());
		prompt_operation_status(true, "");

		m_log = result;
	}
	else {
		prompt_operation_status(false, QString::fromLocal8Bit("����Ϊ��"));
		LOGE_("");
	}

#ifdef uncross_thread_start
	lk.unlock();
#endif
}

// �ͻ�����Ϣ����
void ExportScannerInfo::onUpdateClients() {
	ui.CB_TCPS_CONNECT_CLIENT_IP->clear();
	ui.LE_TCPS_CONTENT_CLIENT_PORT->clear();

	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	// 1. ���¿ͻ�����Ϣ
	m_tcps[temp]->getClientsInfo(m_ClientAddr, m_ClientPort);
	int i = 0;

	for each (auto var in m_ClientAddr) {
		int port = m_ClientPort[i];
		LOGI("%s: %d", var.toStdString().data(), port);
		i++;

		ui.CB_TCPS_CONNECT_CLIENT_IP->addItem(var);
	}

	// 2. ���¿ͻ�����������
	ui.TL_TCPS_CLIENT_COUNT->setText(
		QString::number(m_tcps[temp]->getClientsCount()));
}

// ���¿ͻ����������ݵĽ���״̬
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

// ��ǩ��ʾ����״̬
void ExportScannerInfo::prompt_operation_status(
	bool isSuccess, const QString& labelContent) const {
	ui.TL_PROMPT_OPERATION_STATUS->setText(labelContent); // �����ı�
	ui.TL_PROMPT_OPERATION_STATUS->setAlignment(
		Qt::AlignCenter); // �����ı����뷽ʽΪ����
	QColor   color = isSuccess ? QColor(Qt::blue)
		: QColor(Qt::red); // ����success���������ı���ɫ
	QPalette palette;
	palette.setColor(QPalette::WindowText, color);
	ui.TL_PROMPT_OPERATION_STATUS->setPalette(palette);
}

#pragma endregion

#pragma region TCP �ͻ������Ӵ���

// �������
void ExportScannerInfo::onClicked_PB_TCPC_ADD_CONNECT(){
	m_form_tcpc_add_connect->setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint);
	m_form_tcpc_add_connect->setModal(true);

	if (m_tcpcConnection.size() > 0)
	{
		emit updateConnectionInfo(m_tcpcConnection);
		//m_form_tcpc_add_connect->doUpdateConnectionInfo(m_tcpcConnection);
	}
	else
	{
		m_form_tcpc_add_connect->show();
	}
}

// ��ȡ������ӵ�������Ϣ
void ExportScannerInfo::doStartLogTcpcConnection(const std::vector<Connection>& connection){
	if (connection.size() > 0)
	{
		ui.CB_TCPC_TARGET_IP->clear();
		ui.CB_TCPC_TARGET_PORT->clear();
		m_tcpcConnection.clear();
		m_tcpcConnection.resize(connection.size());
		m_tcpcConnection.insert(m_tcpcConnection.begin(), connection.begin(), connection.end());

		for (auto var : connection)
		{
			ui.CB_TCPC_TARGET_PORT->addItem(QString::number(var.getPort()));
			ui.CB_TCPC_TARGET_IP->addItem(var.getIP());
		}

		int lastIndex = ui.CB_TCPC_TARGET_IP->count() - 1;
		ui.CB_TCPC_TARGET_IP->setCurrentIndex(lastIndex);
		lastIndex = ui.CB_TCPC_TARGET_PORT->count() - 1;
		ui.CB_TCPC_TARGET_PORT->setCurrentIndex(lastIndex);
	}
}

// ָ������
void ExportScannerInfo::onCurrentIndexChanged_CB_TCPC_TARGET_IP(){
	int index = ui.CB_TCPC_TARGET_IP->currentIndex(); // ���¶Է��˿�
	ui.CB_TCPC_TARGET_PORT->setCurrentIndex(index);

	isConnect_change_control_status();
}

// ���ӷ����
void ExportScannerInfo::onClicked_PB_TCPC_CONNECT(){
	int index = ui.CB_TCPC_TARGET_IP->currentIndex();
	if (index < 0)
	{
		return;
	}

	// ����һ��Я��һ�� socket�����ڶ�������м���ָ������������Ϣ����
	bool isBlock = ui.CB_TCPC_CONNECT_MODE->currentIndex() == 0 ? false : true;
	int timeout = ui.HS_TCPC_CONNECT_TIMEOUT->value();
	TcpClient * client = new TcpClient(m_tcpcConnection[index].getIP().toStdString().data(), m_tcpcConnection[index].getPort(), isBlock, timeout);
	m_tcpc.push_back(client);

	connect(client, &TcpClient::logReady, this,
		&ExportScannerInfo::getTcpcRest);

	if (client->ConectToServer())
	{
		m_tcpcConnection[index].setConnected(true);
		prompt_operation_status(true, TPStr.CONNECT);
		LOGI_(TPStr.CONNECT);
	}
	else
	{
		m_tcpc.pop_back();
		m_tcpcConnection[index].setConnected(false);
		client = nullptr;
		prompt_operation_status(false, TPStr.UNCONNECT);
		LOGE_(TPStr.UNCONNECT);
	}

	isConnect_change_control_status();
}

// �Ͽ�����
void ExportScannerInfo::onClicked_PB_TCPC_DISCONNECT(){
	int index = currentTCPC();
	if (index < 0)
	{
		return;
	}

	auto it = m_tcpc.begin();
	auto client = (it + index);
	(*client)->DisConnect();
	m_tcpcConnection[ui.CB_TCPC_TARGET_PORT->currentIndex()].setConnected(false);
	m_tcpc.erase(client);

	isConnect_change_control_status();
}

// ���շ����
void ExportScannerInfo::recvServerMsg(){
	// 1 ȫ���̳߳�

	// 2 ���ӷ�������������� add_task
	/// RecvServerMsg()
}

// ��ʼ����
void ExportScannerInfo::onClicked_PB_TCPC_START_RECV_CONTENT(){
	int index = currentTCPC();
	if (index < 0)
	{
		return;
	}
	
	auto it = m_tcpc.begin() + index;
	connect((*it), &TcpClient::logReady, this,
		&ExportScannerInfo::getTcpcRest);
}

// ֹͣ����
void ExportScannerInfo::onClicked_PB_TCPC_STOP_RECV_CONTENT(){
	int index = currentTCPC();
	if (index < 0)
	{
		return;
	}

	auto it = m_tcpc.begin() + index;
	disconnect((*it), &TcpClient::logReady, this,
		&ExportScannerInfo::getTcpcRest);
}

void ExportScannerInfo::onClicked_PB_TCPC_SEND(){

}

void ExportScannerInfo::isConnect_change_control_status(){
	int index = ui.CB_TCPC_TARGET_IP->currentIndex();
	if (index < 0)
	{
		return;
	}

	bool temp = m_tcpcConnection[index].isConnected(); // ��������״̬
	ui.PB_TCPC_CONNECT->setEnabled(!temp);
	ui.PB_TCPC_DISCONNECT->setEnabled(temp);

	prompt_operation_status(temp, temp ? TPStr.CONNECT : TPStr.UNCONNECT); // ���²�����ǩ

	ui.PB_TCPC_START_RECV_CONTENT->setEnabled(!temp);
	ui.PB_TCPC_STOP_RECV_CONTENT->setEnabled(temp); // ���½���

	if (m_tcpc.size() <= 0)
	{
		return;
	}

	index = currentTCPC();
	if (index < 0)
	{
		return;
	}
	std::string temps = m_tcpc[index]->getLocalPort();
	ui.LE_TCPC_LOCAL_PORT->setText(QString::fromLocal8Bit(temps.data()));// ���±��ض˿�
}

// ��ǰ�ͻ���
int ExportScannerInfo::currentTCPC() const {
	int index = -1;
	index = ui.CB_TCPC_TARGET_IP->currentIndex();
	if (index < 0)
	{
		return -1;
	}

	//bool temp = m_tcpcConnection[index].isConnected();
	//prompt_operation_status(temp, temp ?
	//	TPStr.CONNECT.toStdString().data() : TPStr.UNCONNECT.toStdString().data());
	//if (temp)
	//{
	//	LOGI_(TPStr.CONNECT.toStdString().data());
	//}
	//else
	//{
	//	LOGE_(TPStr.UNCONNECT.toStdString().data());
	//}

	QString ip = ui.CB_TCPC_TARGET_IP->currentText();
	int port = ui.CB_TCPC_TARGET_PORT->currentText().toInt();
	int i = 0;
	for (auto var : m_tcpc)
	{
		if (var->getIp() == ip.toStdString() && var->getPort() == port)
		{
			return i;
		}
		i++;
	}

	return -1;
}

// �źŲ�(�߳�)��ȡtcp�ͻ��˽��յ�����
void ExportScannerInfo::getTcpcRest(const QString & result) {
	if (result.size() > 0) {
		LOGI_(result.toStdString().data());
		ui.TE_TCPC_RECV_CONTENT->append(result.toStdString().data());
		prompt_operation_status(true, "");

		m_log = result.toStdString().data();
	}
	else {
		prompt_operation_status(false, QString::fromLocal8Bit("����Ϊ��"));
		LOGE_("");
	}
}

#pragma endregion
