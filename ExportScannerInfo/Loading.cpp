#include "Loading.h"

Form_Loading::Form_Loading(QWidget* parent) : QDialog(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint) {
	// 创建标签和QMovie，设置初始大小和对齐方式为居中
	label.setAlignment(Qt::AlignCenter);

	movie->setCacheMode(QMovie::CacheAll);
	movie->setScaledSize(QSize(120, 120));
	label.setMovie(movie);
	label.setAutoFillBackground(false);

	// 设置标签大小策略为自适应大小
	label.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	// 创建布局控件并设置标签居中填充整个对话框
	layout.addWidget(&label);
	layout.setAlignment(Qt::AlignCenter);

	setLayout(&layout);

	// 计算并设置对话框居中位置
	const QRect desktopRect = QApplication::desktop()->availableGeometry(this);
	setFixedSize(120, 120);
	move((desktopRect.width() - width()) / 2, (desktopRect.height() - height()) / 2);

	// 显示对话框，并播放GIF动画
	movie->start();
}

//Form_Loading::Form_Loading(QWidget* parent = nullptr) : QDialog(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint) {
//	// 创建标签和QMovie，设置初始大小和对齐方式为居中
//	ui.LE_LOADING_GIF->setAlignment(Qt::AlignCenter);
//
//	movie->setCacheMode(QMovie::CacheAll);
//	movie->setScaledSize(QSize(200, 200));
//	ui.LE_LOADING_GIF->setMovie(movie);
//
//	// 设置标签大小策略为自适应大小
//	ui.LE_LOADING_GIF->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//
//	movie->setCacheMode(QMovie::CacheAll);
//	movie->setScaledSize(QSize(200, 200));
//	ui.LE_LOADING_GIF->setMovie(movie);
//
//	// 创建布局控件并设置将标签居中填充整个窗口
//	//ui.VL_LOADING->addWidget(ui.LE_LOADING_GIF);
//	ui.VL_LOADING->setAlignment(Qt::AlignCenter);
//	ui.VL_LOADING->setContentsMargins(0, 0, 0, 0);
//
//	//setLayout(ui.VL_LOADING);
//
//	// 计算并设置对话框居中位置
//	const QRect desktopRect = QApplication::desktop()->availableGeometry(this);
//	setFixedSize(200, 200);
//	move((desktopRect.width() - width()) / 2, (desktopRect.height() - height()) / 2);
//
//	// 显示对话框，并播放GIF动画
//	movie->start();
//}

Form_Loading::~Form_Loading() {
	movie->stop();
}


// 创建布局控件并设置将标签居中填充整个窗口
//QVBoxLayout* layout = new QVBoxLayout(&window);
//layout->addWidget(&label);
//layout->setAlignment(Qt::AlignCenter);
//layout->setContentsMargins(0, 0, 0, 0);