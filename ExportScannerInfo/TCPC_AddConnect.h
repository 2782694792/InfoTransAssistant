#pragma once
#include "ui_TCPC_AddConnect.h"

#include <QTableWidgetItem>
#include <vector>
#include <QtWidgets/QMainWindow>
#include <qmessagebox.h>
#include <QMenu>
#include <QAction>
#include "qdialog.h"
#include "ExportScannerInfo.h"
#include "ConnectionInfo.h"
#include "ReadOnlyDelegate.h"

#include "belien\identification.h"
#include "belien\log.h"
#include "belien\tcpCheck.hpp"
using namespace belien::identification;
using namespace belien::tcpcheck;

enum class MENUACTION : short
{
	CHECK,
	CLEAR
};

namespace Ui {
    class FORM_TCPC_ADD_CONNECT;
}

class FORM_TCPC_ADD_CONNECT :
	public QDialog
{
    Q_OBJECT;

protected:
	//void showEvent(QShowEvent *event) override;

public:
	explicit FORM_TCPC_ADD_CONNECT(QWidget *parent = nullptr);
	~FORM_TCPC_ADD_CONNECT();

signals:
    void startLogTcpcConnection(const std::vector<Connection>& connection); // 返回记录连接信息

public slots:
	void doUpdateConnectionInfo(const std::vector<Connection>& connection);

    void on_tableWidget_customContextMenuRequested(const QPoint & cpos);

	void onClicked_PB_TARGET_CONNECT_INFO_INSERT(); // 插入新行

	void onClicked_PB_TARGET_CONNECT_INFO_DELETE(); // 删除新行

	void onClicked_PB_TARGET_CONNECT_INFO_REFRESH(); // 应用刷新

	void Check_ConnectInfoTable();

	void Clear_ConnectInfoTable();

private:
	void DoAction_ConnectInfoTable(MENUACTION menuaction_enum);

private:
	QWidget * m_parent;
    Ui::FORM_TCPC_ADD_CONNECT ui;
	std::vector<Connection> m_connection;

	QMenu* m_menu; // 右键菜单
	QAction *m_menu_clear; // 右键清空
	QAction *m_menu_check; // 右键检查

};
