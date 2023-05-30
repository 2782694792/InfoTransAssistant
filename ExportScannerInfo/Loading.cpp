#include "Loading.h"

Form_Loading::Form_Loading(QWidget* parent) : QDialog(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint) {
	// ������ǩ��QMovie�����ó�ʼ��С�Ͷ��뷽ʽΪ����
	label.setAlignment(Qt::AlignCenter);

	movie->setCacheMode(QMovie::CacheAll);
	movie->setScaledSize(QSize(120, 120));
	label.setMovie(movie);
	label.setAutoFillBackground(false);

	// ���ñ�ǩ��С����Ϊ����Ӧ��С
	label.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	// �������ֿؼ������ñ�ǩ������������Ի���
	layout.addWidget(&label);
	layout.setAlignment(Qt::AlignCenter);

	setLayout(&layout);

	// ���㲢���öԻ������λ��
	const QRect desktopRect = QApplication::desktop()->availableGeometry(this);
	setFixedSize(120, 120);
	move((desktopRect.width() - width()) / 2, (desktopRect.height() - height()) / 2);

	// ��ʾ�Ի��򣬲�����GIF����
	movie->start();
}

//Form_Loading::Form_Loading(QWidget* parent = nullptr) : QDialog(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint) {
//	// ������ǩ��QMovie�����ó�ʼ��С�Ͷ��뷽ʽΪ����
//	ui.LE_LOADING_GIF->setAlignment(Qt::AlignCenter);
//
//	movie->setCacheMode(QMovie::CacheAll);
//	movie->setScaledSize(QSize(200, 200));
//	ui.LE_LOADING_GIF->setMovie(movie);
//
//	// ���ñ�ǩ��С����Ϊ����Ӧ��С
//	ui.LE_LOADING_GIF->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//
//	movie->setCacheMode(QMovie::CacheAll);
//	movie->setScaledSize(QSize(200, 200));
//	ui.LE_LOADING_GIF->setMovie(movie);
//
//	// �������ֿؼ������ý���ǩ���������������
//	//ui.VL_LOADING->addWidget(ui.LE_LOADING_GIF);
//	ui.VL_LOADING->setAlignment(Qt::AlignCenter);
//	ui.VL_LOADING->setContentsMargins(0, 0, 0, 0);
//
//	//setLayout(ui.VL_LOADING);
//
//	// ���㲢���öԻ������λ��
//	const QRect desktopRect = QApplication::desktop()->availableGeometry(this);
//	setFixedSize(200, 200);
//	move((desktopRect.width() - width()) / 2, (desktopRect.height() - height()) / 2);
//
//	// ��ʾ�Ի��򣬲�����GIF����
//	movie->start();
//}

Form_Loading::~Form_Loading() {
	movie->stop();
}


// �������ֿؼ������ý���ǩ���������������
//QVBoxLayout* layout = new QVBoxLayout(&window);
//layout->addWidget(&label);
//layout->setAlignment(Qt::AlignCenter);
//layout->setContentsMargins(0, 0, 0, 0);