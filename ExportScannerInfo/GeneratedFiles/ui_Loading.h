/********************************************************************************
** Form generated from reading UI file 'Loading.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_H
#define UI_LOADING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FORM_LOADING
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *VL_LOADING;
    QLabel *LE_LOADING_GIF;

    void setupUi(QWidget *FORM_LOADING)
    {
        if (FORM_LOADING->objectName().isEmpty())
            FORM_LOADING->setObjectName(QStringLiteral("FORM_LOADING"));
        FORM_LOADING->setWindowModality(Qt::WindowModal);
        FORM_LOADING->resize(122, 106);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FORM_LOADING->sizePolicy().hasHeightForWidth());
        FORM_LOADING->setSizePolicy(sizePolicy);
        FORM_LOADING->setFocusPolicy(Qt::NoFocus);
        FORM_LOADING->setAutoFillBackground(true);
        FORM_LOADING->setInputMethodHints(Qt::ImhNone);
        verticalLayoutWidget = new QWidget(FORM_LOADING);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 81, 81));
        VL_LOADING = new QVBoxLayout(verticalLayoutWidget);
        VL_LOADING->setObjectName(QStringLiteral("VL_LOADING"));
        VL_LOADING->setContentsMargins(0, 0, 0, 0);
        LE_LOADING_GIF = new QLabel(verticalLayoutWidget);
        LE_LOADING_GIF->setObjectName(QStringLiteral("LE_LOADING_GIF"));
        LE_LOADING_GIF->setAutoFillBackground(false);
        LE_LOADING_GIF->setPixmap(QPixmap(QString::fromUtf8("images/loading.gif")));
        LE_LOADING_GIF->setScaledContents(true);

        VL_LOADING->addWidget(LE_LOADING_GIF);


        retranslateUi(FORM_LOADING);

        QMetaObject::connectSlotsByName(FORM_LOADING);
    } // setupUi

    void retranslateUi(QWidget *FORM_LOADING)
    {
        FORM_LOADING->setWindowTitle(QApplication::translate("FORM_LOADING", "Form", Q_NULLPTR));
        LE_LOADING_GIF->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FORM_LOADING: public Ui_FORM_LOADING {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_H
