#pragma once
#include <qlabel.h>
#include <QMouseEvent>


enum TextLabelID : int
{
	FTP_SERVER = 0,
	FTP_CLIENT,
	TCP_SERVER,
	TCP_CLIENT,
	PDF_EXPORT,
	UNKNOWN
};

static TextLabelID enum_textLabelClick = TextLabelID::UNKNOWN;

class ClickableLabel : public QLabel
{
	Q_OBJECT

public:
	explicit ClickableLabel(QWidget* parent = nullptr);
	~ClickableLabel();

signals:
	void clicked();

protected:
	virtual void mousePressEvent(QMouseEvent* event);
};

