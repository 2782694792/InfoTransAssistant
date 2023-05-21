#include "ClickableLabel.h"


ClickableLabel::ClickableLabel(QWidget* parent)
{
}


ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked(); // 发出点击信号
    }

    QLabel::mousePressEvent(event);
}


