#include "ExportScannerInfo.h"
#include <qfile.h>
#include <qmessagebox.h>
#include <thread>

#define cross_thread_start
// #define uncross_thread_start

#ifdef uncross_thread_start
#include <condition_variable>
#include <mutex>

bool                    t_canRun = false; // ���干������
std::condition_variable t_cv;
std::mutex              t_mx;
#endif

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
}

void ExportScannerInfo::init_default_widget() {
	emit ui.TL_TCP_SERVER->clicked();

	// setWindowFlags(Qt::FramelessWindowHint);	// ���ô����ޱ߿�
	setAttribute(Qt::WA_TranslucentBackground); // ���ô���͸����
	setWindowOpacity(0.96);
	// setAttribute(Qt::WA_TransparentForMouseEvents);	// ���ñ���������

	ui.PB_TCPS_DISCONTENT_CLIENT->setVisible(false);

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
			TextLabelID::FTP_SERVER); // ���ݴ����İ�ť��������Ҫ��ʾ��QWidget
	}
	else if (label == ui.TL_FTP_CLIENT) {
		ui.STACKWIDGET->setCurrentIndex(TextLabelID::FTP_CLIENT);
	}
#endif
	else {
		QMessageBox::information(NULL, "����", "����pdf",
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes);
	}

	init_sidebar_label(tempID);
}

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

inline static bool isValidPort(int port) {
	// �����ж϶˿ں��Ƿ��� 0 �� 65535 ֮��
	if (port < 0 || port > 65535) {
		return false;
	}
	// �ж��Ƿ��Ǳ����˿ں�
	if (port == 0 || port == 20 || port == 21 || port == 22 || port == 23
		|| port == 25 || port == 53 || port == 80 || port == 110 || port == 143
		|| port == 443 || port == 3306) {
		return false;
	}
	// �˿ںźϷ�
	return true;
}

// ���Ӷ˿ںŵ� CB ��
void ExportScannerInfo::onClicked_PB_TCPS_LISTEN_PORT_CREATE() {
	std::string tempstr = TPServerStr.PORT_ILLEGAL.toStdString();
	bool        isCreate = false;

	if (isValidPort(ui.LE_TCPS_LISTEN_PORT->text().toInt())) {
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
				+ TPServerStr.PORT_ADDING_SUCCESS.toStdString();
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
			tempstr = TPServerStr.PORT_ADDED.toStdString();
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
	if (m_tcps[temp]->isRunning()) {
		m_tcps[temp]->terminate();
	}
	m_tcps[temp]->wait();
	m_tcps[temp]->closeServer();
#endif

	auto i = m_tcps.begin();
	i += temp;
	m_tcps.erase(i);

	QString text = ui.CB_TCPS_LISTEN_PORT_LIST->currentText();
	int     lastIndex = ui.CB_TCPS_LISTEN_PORT_LIST->count() - 1;
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
	emit startGetTcpsLog(); // m_tcps[temp]->start();
	m_tcps[temp]->setPriority(QThread::LowPriority);
#endif

	/// 3 �����ظ�����
	if (m_tcps[temp]->getStatus() != TPServer::LISTENING) {
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
		prompt_operation_status(inListen, TPServerStr.LISTENING);
	}
	else // δ����
	{
		ui.TL_PROMPT_OPERATION_STATUS->setFocus();
		prompt_operation_status(!inListen, TPServerStr.NOT_LISTENED);
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
	if (m_tcps[temp]->getStatus() == TPServer::NOT_LISTENED) {
		prompt_operation_status(false, TPServerStr.NOT_LISTENED);
		return;
	}

	/// 3 ֹͣ����
	m_tcps[temp]->stopListen();
	listenNum -= 1;
	isListen_change_control_status();

	/// 4 �ر��߳�
#ifdef cross_thread_start
	if (m_tcps[temp]->isRunning()) {
		m_tcps[temp]->terminate();
	}
	m_tcps[temp]->wait();
	m_tcps[temp]->exit();
#endif

#ifdef uncross_thread_start
	{
		std::lock_guard< std::mutex > lk(t_mx);
		t_canRun = false;
		LOGI("Stop Listen\n");
	}
	t_cv.notify_all(); // ֪ͨ�����߳�
#endif

	LOGE_("");
}

// ����������������
void ExportScannerInfo::onClicked_PB_TCPS_START_RECV_CONTENT() {
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	m_tcps[temp]->startRecvRequestData();
	onUpdateTcpsRecvOrNone();

	LOGI_("");
}

// ֹͣ����
void ExportScannerInfo::onClicked_PB_TCPS_STOP_RECV_CONTENT() {
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	m_tcps[temp]->stopRecvRequestData();
	onUpdateTcpsRecvOrNone();

	LOGE_("");
}

void ExportScannerInfo::onCurrentindexChanged_CB_TCPS_CONTENT_CLIENT_IP() {
	QString ip = ui.CB_TCPS_CONTENT_CLIENT_IP->currentText();

	int i = 0;
	for each (auto var in m_ClientAddr) {
		if (var == ip) {
			ui.LE_TCPS_CONTENT_CLIENT_PORT->setText(
				QString::number(m_ClientPort[i]));
		}
		i++;
	}
}

void ExportScannerInfo::onStateChanged_CHB_TCPS_ALL_CLIENT(){
	ui.CB_TCPS_CONTENT_CLIENT_IP->setEnabled(true);

	if (ui.CHB_TCPS_ALL_CLIENT->isChecked()) // ����
	{
		ui.CB_TCPS_CONTENT_CLIENT_IP->setEnabled(false);
	}
}

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
		m_tcps[temp]->disconnectedOne(ui.CB_TCPS_CONTENT_CLIENT_IP->currentText(), ui.LE_TCPS_CONTENT_CLIENT_PORT->text().toInt());
	}
	
	LOGI_("");
}

void ExportScannerInfo::onClicked_PB_TCPS_SEND_CLIENT(){
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}
	if (m_tcps[temp]->getClientsCount() <= 0)
	{
		return;
	}
	
	if (ui.CHB_TCPS_ALL_CLIENT->isChecked()) // ����
	{
		int num = ui.SB_TCPS_NUM_SEND->text().toInt();
		QString mess = ui.TE_TCPS_SEND_CONTENT->toPlainText();

		m_tcps[temp]->sendDataToClient(num, mess.toStdString().data());
	}
	else // ָ���ͻ���
	{
		QString ip = ui.CB_TCPS_CONTENT_CLIENT_IP->currentText();
		int port = ui.LE_TCPS_CONTENT_CLIENT_PORT->text().toInt();
		int num = ui.SB_TCPS_NUM_SEND->text().toInt();
		QString mess = ui.TE_TCPS_SEND_CONTENT->toPlainText();

		m_tcps[temp]->sendDataToClient(ip, port, num, mess.toStdString().data());
	}

	LOGI_("");
}

// ��ǰ�����ķ���˶˿�
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
		TPServerStr.PORT_ILLEGAL.toStdString().data());
	LOGE_(TPServerStr.PORT_ILLEGAL.toStdString().data());

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
	ui.CB_TCPS_CONTENT_CLIENT_IP->clear();
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

		ui.CB_TCPS_CONTENT_CLIENT_IP->addItem(var);
	}

	// 2. ���¿ͻ�����������
	ui.TL_TCPS_CLIENT_COUNT->setText(
		QString::number(m_tcps[temp]->getClientsCount()));
}

void ExportScannerInfo::onUpdateTcpsRecvOrNone(){
	int temp = currentTCPS();
	if (temp < 0) {
		return;
	}

	if (m_tcps[temp]->getStatus() == TPServer::RECVING_REQUEST_DATA)
	{
		ui.PB_TCPS_START_RECV_CONTENT->setEnabled(false);
		ui.PB_TCPS_STOP_RECV_CONTENT->setEnabled(true);
		prompt_operation_status(true, TPServerStr.RECVING_REQUEST_DATA);
	}

	if (m_tcps[temp]->getStatus() == TPServer::STOP_RECVED_REQUEST_DATA)
	{
		ui.PB_TCPS_START_RECV_CONTENT->setEnabled(true);
		ui.PB_TCPS_STOP_RECV_CONTENT->setEnabled(false);
		prompt_operation_status(false, TPServerStr.STOP_RECVED_REQUEST_DATA);
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