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
        emit clicked(); // ��������ź�
    }

    QLabel::mousePressEvent(event);
}


