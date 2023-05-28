#include "TcpServer.h"
#include <iostream>

TcpServer::TcpServer(int port)
	: m_log(""), m_port((quint16)port), m_status(TP::PORT_ILLEGAL),
	QThread(nullptr), m_server(nullptr) {}

TcpServer::~TcpServer() {
	if (m_server) {
		m_server = nullptr;
		delete m_server;
	}

	if (m_clients.size() > 0) {
		m_clients.clear();
	}
}

//void TcpServer::run() {
//	// moveToThread(this);
//	LOGI_(QString::fromLocal8Bit("线程运行").toStdString().data());
//}

bool TcpServer::isListen(){
	if (m_server == nullptr)
	{
		return false;
	}

	return m_server->isListening();
}

TP TcpServer::startListen() {
	m_server = new QTcpServer(this);
	m_clients.clear();
	clearLog();

	/// 1 重复监听
	if (m_server->isListening()) {
		return record_result(TP::LISTENING, nullptr, "");
	}

	/// 2 监听所有
	if (!m_server->listen(QHostAddress::Any, m_port)) {
		return record_result(TP::NOT_LISTENED, nullptr,
			m_server->errorString().toStdString().data());
	}

	/// 获取内容
	connect(m_server, &QTcpServer::newConnection, this,
		&TcpServer::onNewConnection); // 连接后开始获取内容

	LOGI("Server started: %d", m_port);

	return record_result(TP::LISTENING, nullptr, "");
}

TP TcpServer::stopListen() {
	record_result(TP::NOT_LISTENED, nullptr, "");
	closeServer();

	return TP::NOT_LISTENED;
}

void TcpServer::onNewConnection() {
	// while (m_server->hasPendingConnections()) 
	{
		QTcpSocket* socket = m_server->nextPendingConnection();

		if (!m_clients.contains(socket)) {
			m_clients.insert(socket);
		}

		record_result(TP::CONNECT, socket);

		connect(socket, &QTcpSocket::readyRead, this, &TcpServer::onReadyRead);
		connect(socket, &QTcpSocket::disconnected, this,
			&TcpServer::doDisconnected);
	}
}

void TcpServer::startRecvRequestData() {
	m_status = TP::RECVING_REQUEST_DATA;
}

void TcpServer::stopRecvRequestData() {
	m_status = TP::STOP_RECVED_REQUEST_DATA;
}

void TcpServer::onReadyRead() {
	clearLog();

	QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
	// if (1) (socket->waitForReadyRead())
	{
		m_mx.lock();

		QByteArray data = socket->readAll();
		if (TCPCheck.isValidData(data)) {
			LOGE_(DataStr.INVALID_SIZE.toStdString().data());
			return;
		}

		if (m_status == TP::STOP_RECVED_REQUEST_DATA) // 停止接收
		{
			record_result(TP::STOP_RECVED_REQUEST_DATA, socket, data);
		}
		else // RECVING_REQUEST_DATA
		{
			record_result(TP::RECVING_REQUEST_DATA, socket, data);
		}

		m_mx.unlock();
	}
}

TP TcpServer::sendDataToClient(int repeatNum, const std::string & message) {
	const QByteArray & mess = QString(message.data()).toLocal8Bit();

	record_result(TP::SENDING, nullptr);
	bool fail = true;

	QMutexLocker lock(&m_mx);

	for (QTcpSocket* client : m_clients) { // 向所有客户端发送消息
		int i = 0;
		do
		{
			try{
				client->write(message.data());
				record_result(TP::SEND_SUCCESS, client, mess);
				fail = false;
			}
			catch (std::exception & e){
				record_result(TP::SEND_FAILURE, client, mess);

				LOGE("[%s:%d] %s", client->peerAddress().toString(), client->peerPort(), TP_Str::GetInstance().SEND_FAILURE.toStdString().data());
			}
			i++;
		} while (i < repeatNum);
	}

	lock.unlock();

	if (fail)
	{
		return TP::UNCONNECT;
	}
	return TP::SEND_SUCCESS;
}

TP TcpServer::sendDataToClient(QString addr, int port, int repeatNum, const std::string & message){
	const QByteArray & mess = QString(message.data()).toLocal8Bit();

	bool fail = true;
	record_result(TP::SENDING, nullptr);

	QMutexLocker lock(&m_mx);

	for each (auto var in m_clients)
	{
		if (var->peerAddress().toString() == addr.toStdString().data() && port == var->peerPort())
		{
			int i = 0;
			do
			{
				i++;
				try{
					var->write(message.data());
				}
				catch (std::exception & e){
					record_result(TP::SEND_FAILURE, var, mess);

					LOGE("[%s:%d] %s", var->peerAddress().toString(), var->peerPort(), TP_Str::GetInstance().SEND_FAILURE.toStdString().data());

					fail = true;
				}

				record_result(TP::SEND_SUCCESS, var, mess);
			} while (i < repeatNum);

			fail = false;
		}
	}

	lock.unlock();

	if (fail)
	{
		return TP::UNCONNECT;
	}
	return TP::SEND_SUCCESS;
}

TP TcpServer::doDisconnected() {
	QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
	if (m_clients.contains(socket)) {
		m_clients.remove(socket);
		socket->deleteLater();
	}

	return record_result(TP::DISCONNECT, socket);
}

TP TcpServer::disconnectedOne(QString addr, int port){
	for each (auto var in m_clients)
	{
		if (m_clients.size() <= 0)
		{
			break;
		}

		if (var->peerAddress().toString() == addr.toStdString().data() && port == var->peerPort())
		{
			m_clients.remove(var);
			var->deleteLater();
		}
	}

	return record_result(TP::UNCONNECT, nullptr);
}

TP TcpServer::disconnectedAll(){
	bool fail = true;
	{
		QMutexLocker lock(&m_mx);

		for (auto socket : m_clients)
		{
			if (m_clients.size() <= 0)
			{
				break;
			}

			fail = false;
			m_clients.remove(socket);
			socket->deleteLater();
		}

		lock.unlock();
	}
	if (fail)
	{
		return record_result(TP::UNCONNECT, nullptr);
	}
	return record_result(TP::DISCONNECT, nullptr);
}


void TcpServer::closeServer() {
	LOGE("%s:%s", QString::fromLocal8Bit("连接数").toStdString().data(),
		QString::number(m_clients.size()).data());

	const QList<QTcpSocket*> ptemp = m_clients.toList();
	for each (auto var in ptemp)
	{
		var->disconnectFromHost();
		var->close();
	}

	m_clients.clear();
	m_server->close();
}

int TcpServer::getClientsCount() {
	return m_clients.size();
}

void TcpServer::getClientsInfo(QStringList& addrs, QList< int >& ports) {
	addrs.clear();
	ports.clear();

	for each (auto var in m_clients) {
		addrs.push_back((*var).peerAddress().toString());
		ports.push_back((*var).peerPort());
	}
}

TP TcpServer::record_result(TP rest, const QTcpSocket* client,
	const QByteArray& data) {
	QString id = "", id2 = "";

	if (client != nullptr) {
		std::string temp = client->peerAddress().toString().toStdString();
		int         pos = temp.find_first_of('1');
		QString     ip = temp.substr(pos).data(); // 获取IP地址
		int         port = client->peerPort();      // 获取端口号
		id = QString("[%1: %2] > [%3] %4\n")
			.arg(ip)
			.arg(port)
			.arg((int)(m_server->serverPort()));
		id2 = QString("[%3] > [%1: %2] %4\n")
			.arg(ip)
			.arg(port)
			.arg((int)(m_server->serverPort()));
	}
	else {
		id = QString("(%1) %2\n").arg((int)(m_server->serverPort()));
	}

	bool isEmit = false;

	m_status = rest;
	switch (m_status) {
	case belien::identification::TP::CONNECT:
		isEmit = true;
		m_log = id.arg(TPStr.CONNECT);
		emit updateClientsReady();
		break;
	case belien::identification::TP::DISCONNECT:
		isEmit = true;
		m_log = id.arg(TPStr.DISCONNECT);
		emit updateClientsReady();
		break;
	case belien::identification::TP::RECVING_REQUEST_DATA:
		if (!data.isEmpty()) {
			isEmit = true;
			m_log = id.arg(QString::fromLocal8Bit(data));
		}
		break;
	case belien::identification::TP::STOP_RECVED_REQUEST_DATA:
		m_log = id.arg(TPStr.STOP_RECVED_REQUEST_DATA);
		break;
	case belien::identification::TP::LISTENING:
		m_log = id.arg(TPStr.LISTENING);
		break;
	case belien::identification::TP::NOT_LISTENED:
		m_log = id.arg(TPStr.NOT_LISTENED);
		break;
	case belien::identification::TP::SENDING:
		m_log = id2.arg(TPStr.SENDING);
		break;
	case belien::identification::TP::SEND_SUCCESS:
		m_log = id2.arg(QString::fromLocal8Bit(data));
		isEmit = true;
		break;
	case belien::identification::TP::SEND_FAILURE:
		m_log = id2.arg(QString::fromLocal8Bit(data) + TPStr.SEND_FAILURE);
		break;
	case belien::identification::TP::REQUEST_CONNECT:
		break;
	case belien::identification::TP::UNCONNECT:
		m_log = id.arg(TPStr.UNCONNECT);
		break;
	case belien::identification::TP::PORT_ILLEGAL:
		break;
	default:
		break;
	}

	LOGI_(m_log.toStdString().data());
	if (isEmit) {
		emit logReady(m_log);
	}

	return m_status;
}
