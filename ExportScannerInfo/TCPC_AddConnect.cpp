#include "TCPC_AddConnect.h"

FORM_TCPC_ADD_CONNECT::FORM_TCPC_ADD_CONNECT(QWidget *parent) :
QDialog(parent)
{
	ui.setupUi(this);
}

FORM_TCPC_ADD_CONNECT::~FORM_TCPC_ADD_CONNECT()
{
}

void FORM_TCPC_ADD_CONNECT::onClicked_PB_TARGET_CONNECT_INFO_INSERT(){
	auto tableWidget = ui.TW_TARGET_CONNECT_INFO;

	int rowCount = tableWidget->rowCount();
	int columnCount = tableWidget->columnCount();

	tableWidget->insertRow(rowCount);

	tableWidget->scrollToBottom();
	tableWidget->selectRow(rowCount);

	// 自动调整列宽和行高
	//tableWidget->resizeColumnsToContents();
	//tableWidget->resizeRowsToContents();
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

