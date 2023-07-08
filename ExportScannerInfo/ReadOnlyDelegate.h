#pragma once
#include <QItemDelegate>

class ReadOnlyDelegate :
	public QItemDelegate
{
public:
	ReadOnlyDelegate(QWidget *parent = NULL);
	~ReadOnlyDelegate();
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const override;
};

