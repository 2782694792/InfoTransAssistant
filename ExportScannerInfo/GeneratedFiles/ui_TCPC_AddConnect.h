/********************************************************************************
** Form generated from reading UI file 'TCPC_AddConnect.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPC_ADDCONNECT_H
#define UI_TCPC_ADDCONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FORM_TCPC_ADD_CONNECT
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *TW_TARGET_CONNECT_INFO;
    QVBoxLayout *verticalLayout;
    QPushButton *PB_TARGET_CONNECT_INFO_INSERT;
    QPushButton *PB_TARGET_CONNECT_INFO_DELETE;
    QSpacerItem *verticalSpacer;
    QPushButton *PB_TARGET_CONNECT_INFO_REFRESH;

    void setupUi(QWidget *FORM_TCPC_ADD_CONNECT)
    {
        if (FORM_TCPC_ADD_CONNECT->objectName().isEmpty())
            FORM_TCPC_ADD_CONNECT->setObjectName(QStringLiteral("FORM_TCPC_ADD_CONNECT"));
        FORM_TCPC_ADD_CONNECT->resize(512, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FORM_TCPC_ADD_CONNECT->sizePolicy().hasHeightForWidth());
        FORM_TCPC_ADD_CONNECT->setSizePolicy(sizePolicy);
        FORM_TCPC_ADD_CONNECT->setMinimumSize(QSize(400, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        FORM_TCPC_ADD_CONNECT->setFont(font);
        gridLayout_2 = new QGridLayout(FORM_TCPC_ADD_CONNECT);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        TW_TARGET_CONNECT_INFO = new QTableWidget(FORM_TCPC_ADD_CONNECT);
        if (TW_TARGET_CONNECT_INFO->columnCount() < 3)
            TW_TARGET_CONNECT_INFO->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        TW_TARGET_CONNECT_INFO->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        TW_TARGET_CONNECT_INFO->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        TW_TARGET_CONNECT_INFO->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        TW_TARGET_CONNECT_INFO->setObjectName(QStringLiteral("TW_TARGET_CONNECT_INFO"));
        TW_TARGET_CONNECT_INFO->setMinimumSize(QSize(240, 0));
        TW_TARGET_CONNECT_INFO->setFrameShadow(QFrame::Sunken);
        TW_TARGET_CONNECT_INFO->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TW_TARGET_CONNECT_INFO->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TW_TARGET_CONNECT_INFO->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        TW_TARGET_CONNECT_INFO->setSortingEnabled(true);

        verticalLayout_3->addWidget(TW_TARGET_CONNECT_INFO);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, -1, 2, -1);
        PB_TARGET_CONNECT_INFO_INSERT = new QPushButton(FORM_TCPC_ADD_CONNECT);
        PB_TARGET_CONNECT_INFO_INSERT->setObjectName(QStringLiteral("PB_TARGET_CONNECT_INFO_INSERT"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PB_TARGET_CONNECT_INFO_INSERT->sizePolicy().hasHeightForWidth());
        PB_TARGET_CONNECT_INFO_INSERT->setSizePolicy(sizePolicy1);
        PB_TARGET_CONNECT_INFO_INSERT->setMinimumSize(QSize(0, 35));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        PB_TARGET_CONNECT_INFO_INSERT->setFont(font1);

        verticalLayout->addWidget(PB_TARGET_CONNECT_INFO_INSERT);

        PB_TARGET_CONNECT_INFO_DELETE = new QPushButton(FORM_TCPC_ADD_CONNECT);
        PB_TARGET_CONNECT_INFO_DELETE->setObjectName(QStringLiteral("PB_TARGET_CONNECT_INFO_DELETE"));
        sizePolicy1.setHeightForWidth(PB_TARGET_CONNECT_INFO_DELETE->sizePolicy().hasHeightForWidth());
        PB_TARGET_CONNECT_INFO_DELETE->setSizePolicy(sizePolicy1);
        PB_TARGET_CONNECT_INFO_DELETE->setMinimumSize(QSize(12, 35));
        PB_TARGET_CONNECT_INFO_DELETE->setFont(font1);

        verticalLayout->addWidget(PB_TARGET_CONNECT_INFO_DELETE);

        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        PB_TARGET_CONNECT_INFO_REFRESH = new QPushButton(FORM_TCPC_ADD_CONNECT);
        PB_TARGET_CONNECT_INFO_REFRESH->setObjectName(QStringLiteral("PB_TARGET_CONNECT_INFO_REFRESH"));
        sizePolicy1.setHeightForWidth(PB_TARGET_CONNECT_INFO_REFRESH->sizePolicy().hasHeightForWidth());
        PB_TARGET_CONNECT_INFO_REFRESH->setSizePolicy(sizePolicy1);
        PB_TARGET_CONNECT_INFO_REFRESH->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(PB_TARGET_CONNECT_INFO_REFRESH);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(FORM_TCPC_ADD_CONNECT);
        QObject::connect(PB_TARGET_CONNECT_INFO_INSERT, SIGNAL(clicked()), FORM_TCPC_ADD_CONNECT, SLOT(onClicked_PB_TARGET_CONNECT_INFO_INSERT()));
        QObject::connect(PB_TARGET_CONNECT_INFO_DELETE, SIGNAL(clicked()), FORM_TCPC_ADD_CONNECT, SLOT(onClicked_PB_TARGET_CONNECT_INFO_DELETE()));
        QObject::connect(PB_TARGET_CONNECT_INFO_REFRESH, SIGNAL(clicked()), FORM_TCPC_ADD_CONNECT, SLOT(onClicked_PB_TARGET_CONNECT_INFO_REFRESH()));

        QMetaObject::connectSlotsByName(FORM_TCPC_ADD_CONNECT);
    } // setupUi

    void retranslateUi(QWidget *FORM_TCPC_ADD_CONNECT)
    {
        FORM_TCPC_ADD_CONNECT->setWindowTitle(QApplication::translate("FORM_TCPC_ADD_CONNECT", "\350\277\236\346\216\245\347\256\241\347\220\206", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = TW_TARGET_CONNECT_INFO->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FORM_TCPC_ADD_CONNECT", "\347\233\256\346\240\207 IP", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = TW_TARGET_CONNECT_INFO->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FORM_TCPC_ADD_CONNECT", "\347\233\256\346\240\207\347\253\257\345\217\243", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = TW_TARGET_CONNECT_INFO->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FORM_TCPC_ADD_CONNECT", "\346\230\257\345\220\246\350\277\236\346\216\245", Q_NULLPTR));
        PB_TARGET_CONNECT_INFO_INSERT->setText(QApplication::translate("FORM_TCPC_ADD_CONNECT", "+", Q_NULLPTR));
        PB_TARGET_CONNECT_INFO_DELETE->setText(QApplication::translate("FORM_TCPC_ADD_CONNECT", "-", Q_NULLPTR));
        PB_TARGET_CONNECT_INFO_REFRESH->setText(QApplication::translate("FORM_TCPC_ADD_CONNECT", "\345\272\224\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FORM_TCPC_ADD_CONNECT: public Ui_FORM_TCPC_ADD_CONNECT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPC_ADDCONNECT_H
