#include "TCPC_AddConnect.h"

FORM_TCPC_ADD_CONNECT::FORM_TCPC_ADD_CONNECT(QWidget *parent) :
m_parent(parent)
{
	ui.setupUi(this);

	//// 获取父窗口指针 1
	//QWidget *m_parentWnd;
	//m_parentWnd = parent;

	//// 获取父窗口指针 2
	//QWidget* parentWidget = new ExportScannerInfo();
	//// 将父窗口指针转换为 MainWindow 类指针
	//QMainWindow* mainWindow = qobject_cast<QMainWindow*>(parentWidget);
	//// 检查转换是否成功
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
	m_menu_check = m_menu->addAction(QString::fromLocal8Bit("检查"));
	m_menu->addSeparator();
	m_menu_clear = m_menu->addAction(QString::fromLocal8Bit("清空"));

	connect(m_menu_check, SIGNAL(triggered()), this, SLOT(Check_ConnectInfoTable()));
	connect(m_menu_clear, SIGNAL(triggered()), this, SLOT(Clear_ConnectInfoTable()));

	m_menu->exec(QCursor::pos()); // 光标位置呼出
	m_menu->clear();
	m_menu = nullptr;
	//}

	//status *= -1;	
}

//void FORM_TCPC_ADD_CONNECT::showEvent(QShowEvent *event) {
//	// 首先调用父类的 showEvent 函数
//	//QWidget::showEvent(event);
//
//	//// 拿到父窗口对象指针
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
					QMessageBox::critical(this, QString::fromLocal8Bit("连接检查"), QString::fromLocal8Bit("非法连接：%1: %2").arg(ip).arg(port), QMessageBox::Ok);
				}
			}
			break;
		case MENUACTION::CLEAR:
			if (!isEmpty && tableWidget->item(row, 2)->text() != "false")
			{
				QMessageBox::critical(this, QString::fromLocal8Bit("连接清空"), QString::fromLocal8Bit("%1: %2 已连接，请先断开！").arg(tableWidget->item(row, 0)->text()).arg(tableWidget->item(row, 1)->text()), QMessageBox::Ok);
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

		//tableWidget->clearContents(); // 清除子项行
		for (int i = tableWidget->rowCount() - 1; i >= 0; --i) {
			tableWidget->removeRow(i); // 从最后一行开始逆序删除
		}

		for (int i = 0; i < count; i++) // 添加子项行
		{
			tableWidget->insertRow(i);
		}

		for (int row = 0; row < count; row++) { // 设置单元格值
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

	// 自动调整列宽和行高
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
				QMessageBox::critical(this, QString::fromLocal8Bit("删除检查"), QString::fromLocal8Bit("%1: %2 已连接，请先断开！").arg(tableWidget->item(row, 0)->text()).arg(tableWidget->item(row, 1)->text()), QMessageBox::Ok);

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
			LOGE("%s:%d %s", ip.toStdString().data(), port, QString::fromLocal8Bit("非法连接").toStdString().data());

			QMessageBox::critical(this, QString::fromLocal8Bit("信息检查"), QString::fromLocal8Bit("非法连接：%1: %2").arg(ip).arg(port), QMessageBox::Ok);

			//QLabel * label = m_parent->findChild<QLabel*>("TL_PROMPT_OPERATION_STATUS");
			//label->setText(QString::fromLocal8Bit("存在非法连接").toStdString().data());
		}
	}

	if (!iserror)
	{
		emit startLogTcpcConnection(m_connection);
		this->close();
	}
}
