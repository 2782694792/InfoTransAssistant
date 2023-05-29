#include "TCPC_AddConnect.h"

FORM_TCPC_ADD_CONNECT::FORM_TCPC_ADD_CONNECT(QWidget *parent) :
QDialog(parent)
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

	ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
	ui.TW_TARGET_CONNECT_INFO->setItemDelegateForColumn(2, readOnlyDelegate);
}

FORM_TCPC_ADD_CONNECT::~FORM_TCPC_ADD_CONNECT()
{
}

void FORM_TCPC_ADD_CONNECT::showEvent(QShowEvent *event) {
	// ���ȵ��ø���� showEvent ����
	//QWidget::showEvent(event);

	//// �õ������ڶ���ָ��
	//QMainWindow *parentWidget = qobject_cast<QMainWindow *>(sender()->parent());
	//if (!parentWidget) {
	//    return;
	//}
}

void FORM_TCPC_ADD_CONNECT::doUpdateConnectionInfo(const std::vector<Connection>& connection){
	std::vector<Connection> connectionInfo = connection;
	int count = connectionInfo.size();
	if (count > 0)
	{
		QTableWidget *tableWidget = findChild<QTableWidget *>("TW_TARGET_CONNECT_INFO");
		
		// ���������
		//tableWidget->clearContents();
		for (int i = tableWidget->rowCount() - 1; i >= 0; --i) {
			tableWidget->removeRow(i); // �����һ�п�ʼ����ɾ��
		}

		// ���������
		for (int i = 0; i < count; i++)
		{
			tableWidget->insertRow(i);
		}

		// ���õ�Ԫ��ֵ
		for (int row = 0; row < count; row++) {
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

	if (rowCount > 0) {
		m_connection.clear();

		for (int row = 0; row < rowCount; row++)
		{
			QTableWidgetItem* item = tableWidget->item(row, 0);
			QTableWidgetItem* item1 = tableWidget->item(row, 1);
			QTableWidgetItem* item2 = tableWidget->item(row, 2);
			if (item && !item->text().isEmpty() && item1 && !item1->text().isEmpty())
			{
				QString ip = item->text();
				int port = item1->text().toInt();
				bool isconnect = item2->text().toStdString() == "false" ? false : true;
				if (TCPCheck.isIPValid(ip) && TCPCheck.isValidPort(port))
				{
					m_connection.push_back(Connection(ip, port, isconnect));
					iserror = false;
				}
				else
				{
					LOGE("%s:%d %s", ip.toStdString().data(), port, QString::fromLocal8Bit("�Ƿ�����").toStdString().data());
				}
			}
		}

		if (!iserror)
		{
			emit startLogTcpcConnection(m_connection);
		}

		this->close();
	}
}

