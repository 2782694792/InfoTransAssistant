#include "TCPC_AddConnect.h"

FORM_TCPC_ADD_CONNECT::FORM_TCPC_ADD_CONNECT(QWidget *parent) :
QDialog(parent)
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
}

FORM_TCPC_ADD_CONNECT::~FORM_TCPC_ADD_CONNECT()
{
}

void FORM_TCPC_ADD_CONNECT::showEvent(QShowEvent *event) {
    // 首先调用父类的 showEvent 函数
    //QWidget::showEvent(event);

    //// 拿到父窗口对象指针
    //QMainWindow *parentWidget = qobject_cast<QMainWindow *>(sender()->parent());
    //if (!parentWidget) {
    //    return;
    //}
}

void FORM_TCPC_ADD_CONNECT::doUpdateConnectionInfo(const std::vector<Connection>& connection){
	m_connection.clear();
	m_connection.insert(m_connection.begin(), connection.begin(), connection.end());
	
    QTableWidget *tableWidget = findChild<QTableWidget *>("TW_TARGET_CONNECT_INFO");
	if (m_connection.size() > 0)
	{
		for (int row = 0; row < m_connection.size(); row++) {
			QTableWidgetItem *item1 = new QTableWidgetItem(
				tr("%1").arg(m_connection[row].getIP())
				);
			QTableWidgetItem *item2 = new QTableWidgetItem(
				tr("%1").arg(m_connection[row].getPort())
				);
			tableWidget->setItem(row, 0, item1);
			tableWidget->setItem(row, 1, item2);
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
	int columnCount = tableWidget->columnCount();

	tableWidget->insertRow(rowCount);

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
	m_connection.clear();

	auto tableWidget = ui.TW_TARGET_CONNECT_INFO;
	int rowCount = tableWidget->rowCount();

	bool iserror = true;

	if (rowCount > 0) {
		for (int row = 0; row < rowCount; row++)
		{
			QTableWidgetItem* item = tableWidget->item(row, 0);
			QTableWidgetItem* item1 = tableWidget->item(row, 1);
			if (item && !item->text().isEmpty() && item1 && !item1->text().isEmpty())
			{
				QString ip = item->text();
				int port = item1->text().toInt();
				if (IpPort.isIPValid(ip) && IpPort.isValidPort(port))
				{
					m_connection.push_back(Connection(ip, port));
					iserror = false;
				}
				else
				{
					LOGE("%s:%d %s", ip.toStdString().data(), port, QString::fromLocal8Bit("非法连接").toStdString().data());
				}
			}
		}

		if (!iserror)
		{
			emit startLogTcpcConnection(m_connection);

			this->close();
		}
	}
}

