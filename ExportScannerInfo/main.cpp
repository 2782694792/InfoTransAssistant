#include "ExportScannerInfo.h"
#include <QtWidgets/QApplication>
#include <QString>
#include <QtNetwork\qhostinfo.h>
#include <QGuiApplication>
#include <QScreen>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	ExportScannerInfo w;
	w.show();
	w.setGeometry(
		QStyle::alignedRect(
		Qt::LeftToRight,
		Qt::AlignCenter,
		w.size(), // 窗口的大小
		qApp->primaryScreen()->availableGeometry() // 屏幕的可用大小
	));

	return a.exec();
}
