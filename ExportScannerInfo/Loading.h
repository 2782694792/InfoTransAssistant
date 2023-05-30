#pragma once
#include "ui_Loading.h"

#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QTimer>
#include <QMovie>
#include <QDesktopWidget>
#include <QSizePolicy>
namespace Ui {
	class FORM_LOADING;
}

class Form_Loading :
	public QDialog
{
	Q_OBJECT;
public:
	Form_Loading(QWidget* parent = nullptr);

	~Form_Loading();

private:
	Ui::FORM_LOADING ui;
	QVBoxLayout layout;
	QLabel label;
	QMovie* movie = new QMovie("./images/loading.gif", QByteArray(), this);
};
