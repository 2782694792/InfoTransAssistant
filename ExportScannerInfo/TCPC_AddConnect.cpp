#include "TCPC_AddConnect.h"

FORM_TCPC_ADD_CONNECT::FORM_TCPC_ADD_CONNECT(QWidget *parent) :
m_parent(parent)
{
	ui.setupUi(this);

	//// ��ȡ������ָ�� 1
	//QWidget *m_parentWnd;
	//m_parentWnd = parent;

	//// ��ȡ������ָ�� 2
	//QWidget* parentWidget = new ExportScannerInfo();
	//// ��������ָ��ת��Ϊ MainWindow ��ָ��
	//QMainWindow* mainWindow = qobject_cast<QMainWindow*>(parentWidget);
	//// ���ת���Ƿ�ɹ�
	//if (mainWindow != nullptr) {
	//}

	connect(ui.TW_TARGET_CONNECT_INFO, SIGNAL(customContextMenuRequested(QPoint)), this,
		SLOT(on_tableWidget_customContextMenuRequested(QPoint)));

	ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
	ui.TW_TARGET_CONNECT_INFO->setItemDelegateForColumn(2, readOnlyDelegate);
}

FORM_TCPC_ADD_CONNECT::~FORM_TCPC_ADD_CONNECT()
{
	m_connection.clear();
}

void FORM_TCPC_ADD_CONNECT::on_tableWidget_customContextMenuRequested(const QPoint & cpos){
	//static int status = 1;
	//if (status == 1) {
	if (ui.TW_TARGET_CONNECT_INFO->rowCount() == 0)
	{
		return;

		m_menu_clear->setEnabled(false);
		m_menu_check->setEnabled(false);
	}

	m_menu = new QMenu(this);
	m_menu_check = m_menu->addAction(QString::fromLocal8Bit("���"));
	m_menu->addSeparator();
	m_menu_clear = m_menu->addAction(QString::fromLocal8Bit("���"));

	connect(m_menu_check, SIGNAL(triggered()), this, SLOT(Check_ConnectInfoTable()));
	connect(m_menu_clear, SIGNAL(triggered()), this, SLOT(Clear_ConnectInfoTable()));

	m_menu->exec(QCursor::pos()); // ���λ�ú���
	m_menu->clear();
	m_menu = nullptr;
	//}

	//status *= -1;	
}

//void FORM_TCPC_ADD_CONNECT::showEvent(QShowEvent *event) {
//	// ���ȵ��ø���� showEvent ����
//	//QWidget::showEvent(event);
//
//	//// �õ������ڶ���ָ��
//	//QMainWindow *parentWidget = qobject_cast<QMainWindow *>(sender()->parent());
//	//if (!parentWidget) {
//	//    return;
//	//}
//}

void FORM_TCPC_ADD_CONNECT::Check_ConnectInfoTable(){
	DoAction_ConnectInfoTable(MENUACTION::CHECK);

	disconnect(m_menu_check, SIGNAL(triggered()), this, SLOT(Check_ConnectInfoTable()));
}

void FORM_TCPC_ADD_CONNECT::Clear_ConnectInfoTable(){
	DoAction_ConnectInfoTable(MENUACTION::CLEAR);
	
	disconnect(m_menu_clear, SIGNAL(triggered()), this, SLOT(Clear_ConnectInfoTable()));
}

void FORM_TCPC_ADD_CONNECT::DoAction_ConnectInfoTable(MENUACTION menuaction_enum){
	auto tableWidget = ui.TW_TARGET_CONNECT_INFO;
	int rowCount = tableWidget->rowCount();
	for (int row = 0; row < rowCount; row++)
	{
		bool isEmpty = false;
		QTableWidgetItem* item = tableWidget->item(row, 0);
		QTableWidgetItem* item1 = tableWidget->item(row, 1);
		if (!(item && !item->text().isEmpty() && item1 && !item1->text().isEmpty()))
		{
			isEmpty = true;
		}

		switch (menuaction_enum)
		{
		case MENUACTION::CHECK:
			if (!isEmpty)
			{
				QString ip = item->text();
				int port = item1->text().toInt();
				if (!(TCPCheck.isIPValid(ip) && TCPCheck.isValidPort(port)))
				{
					QMessageBox::critical(this, QString::fromLocal8Bit("���Ӽ��"), QString::fromLocal8Bit("�Ƿ����ӣ�%1: %2").arg(ip).arg(port), QMessageBox::Ok);
				}
			}
			break;
		case MENUACTION::CLEAR:
			if (!isEmpty && tableWidget->item(row, 2)->text() != "false")
			{
				QMessageBox::critical(this, QString::fromLocal8Bit("�������"), QString::fromLocal8Bit("%1: %2 �����ӣ����ȶϿ���").arg(tableWidget->item(row, 0)->text()).arg(tableWidget->item(row, 1)->text()), QMessageBox::Ok);
			}
			else
			{
				tableWidget->removeRow(row);
			}
			break;
		default:
			break;
		}
	}
}

void FORM_TCPC_ADD_CONNECT::doUpdateConnectionInfo(const std::vector<Connection>& connection){
	std::vector<Connection> connectionInfo = connection;
	int count = connectionInfo.size();
	if (count > 0)
	{
		QTableWidget *tableWidget = findChild<QTableWidget *>("TW_TARGET_CONNECT_INFO");

		//tableWidget->clearContents(); // ���������
		for (int i = tableWidget->rowCount() - 1; i >= 0; --i) {
			tableWidget->removeRow(i); // �����һ�п�ʼ����ɾ��
		}

		for (int i = 0; i < count; i++) // ���������
		{
			tableWidget->insertRow(i);
		}

		for (int row = 0; row < count; row++) { // ���õ�Ԫ��ֵ
			QTableWidgetItem *item1 = new QTableWidgetItem(
				tr("%1").arg(connectionInfo[row].getIP())
				);
			QTableWidgetItem *item2 = new QTableWidgetItem(
				tr("%1").arg(connectionInfo[row].getPort())
				);
			QTableWidgetItem *item3 = new QTableWidgetItem(
				tr("%1").arg(connectionInfo[row].isConnected() ? "true" : "false")
				);
			tableWidget->setItem(row, 0, item1);
			tableWidget->setItem(row, 1, item2);
			tableWidget->setItem(row, 2, item3);
		}
	}

	// �Զ������п���и�
	//tableWidget->resizeColumnsToContents();
	//tableWidget->resizeRowsToContents();

	show();
}

void FORM_TCPC_ADD_CONNECT::onClicked_PB_TARGET_CONNECT_INFO_INSERT(){
	auto tableWidget = ui.TW_TARGET_CONNECT_INFO;

	int rowCount = tableWidget->rowCount();

	tableWidget->insertRow(rowCount);
	QTableWidgetItem *item3 = new QTableWidgetItem(
		tr("%1").arg("false"));
	tableWidget->setItem(rowCount, 2, item3);

	tableWidget->scrollToBottom();
	tableWidget->selectRow(rowCount);
}

void FORM_TCPC_ADD_CONNECT::onClicked_PB_TARGET_CONNECT_INFO_DELETE(){
	auto tableWidget = ui.TW_TARGET_CONNECT_INFO;

	int rowCount = tableWidget->rowCount();
	if (rowCount > 0) {
		QItemSelectionModel *select = tableWidget->selectionModel();
		QModelIndexList selectedRows = select->selectedRows();
		int row = 0;
		for (int i = selectedRows.count() - 1; i >= 0; i--) {
			row = selectedRows.at(i).row();
			QString col_3 = tableWidget->item(row, 2)->text();
			if (col_3 != "false")
			{
				QMessageBox::critical(this, QString::fromLocal8Bit("ɾ�����"), QString::fromLocal8Bit("%1: %2 �����ӣ����ȶϿ���").arg(tableWidget->item(row, 0)->text()).arg(tableWidget->item(row, 1)->text()), QMessageBox::Ok);

				continue;
			}

			tableWidget->removeRow(row);
		}
	}
	//int rowCount = tableWidget->rowCount();
	//if (rowCount > 0) {
	//	tableWidget->removeRow(rowCount - 1);
	//	if (rowCount > 1) {
	//		tableWidget->selectRow(rowCount - 2);
	//	}
	//}
}

void FORM_TCPC_ADD_CONNECT::onClicked_PB_TARGET_CONNECT_INFO_REFRESH(){
	auto tableWidget = ui.TW_TARGET_CONNECT_INFO;
	int rowCount = tableWidget->rowCount();

	bool iserror = true;

	if (rowCount <= 0) {
		this->close();
		return;
	}

	m_connection.clear();

	for (int row = 0; row < rowCount; row++)
	{
		QTableWidgetItem* item = tableWidget->item(row, 0);
		QTableWidgetItem* item1 = tableWidget->item(row, 1);
		if (!(item && !item->text().isEmpty() && item1 && !item1->text().isEmpty()))
		{
			continue;
		}

		QString ip = item->text();
		int port = item1->text().toInt();
		QTableWidgetItem* item2 = tableWidget->item(row, 2);
		bool isconnect = item2->text().toStdString() == "false" ? false : true;
		if (TCPCheck.isIPValid(ip) && TCPCheck.isValidPort(port))
		{
			m_connection.push_back(Connection(ip, port, isconnect));
			iserror = false;
		}
		else
		{
			LOGE("%s:%d %s", ip.toStdString().data(), port, QString::fromLocal8Bit("�Ƿ�����").toStdString().data());

			QMessageBox::critical(this, QString::fromLocal8Bit("��Ϣ���"), QString::fromLocal8Bit("�Ƿ����ӣ�%1: %2").arg(ip).arg(port), QMessageBox::Ok);

			//QLabel * label = m_parent->findChild<QLabel*>("TL_PROMPT_OPERATION_STATUS");
			//label->setText(QString::fromLocal8Bit("���ڷǷ�����").toStdString().data());
		}
	}

	if (!iserror)
	{
		emit startLogTcpcConnection(m_connection);
		this->close();
	}
}
