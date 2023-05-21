/********************************************************************************
** Form generated from reading UI file 'ExportScannerInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTSCANNERINFO_H
#define UI_EXPORTSCANNERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"

QT_BEGIN_NAMESPACE

class Ui_ExportScannerInfoClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *TL_PROMPT_OPERATION_STATUS;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_14;
    QLabel *TL_TCP;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_17;
    ClickableLabel *TL_TCP_SERVER;
    QLabel *TL_TCP_SERVER_ICON;
    QHBoxLayout *horizontalLayout_18;
    ClickableLabel *TL_TCP_CLIENT;
    QLabel *TL_TCP_CLIENT_ICON;
    QSpacerItem *verticalSpacer;
    QLabel *TL_PDF;
    QFrame *line;
    QHBoxLayout *horizontalLayout_19;
    ClickableLabel *TL_PDF_EXPORT;
    QLabel *TL_PDF_EXPORT_ICON;
    QSpacerItem *verticalSpacer_2;
    QLabel *TL_FTP;
    QHBoxLayout *horizontalLayout_20;
    ClickableLabel *TL_FTP_SERVER;
    QLabel *TL_FTP_SERVER_ICON;
    QHBoxLayout *horizontalLayout_21;
    ClickableLabel *TL_FTP_CLIENT;
    QLabel *TL_FTP_CLIENT_ICON;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *STACKWIDGET;
    QWidget *SW_FTP_SERVER;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox;
    QTableView *tableView;
    QWidget *SW_FTP_CLIENT;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton;
    QWidget *SW_TCP_SERVER;
    QWidget *gridWidget_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *CHB_TCPS_ALL_CLIENT;
    QLabel *label_10;
    QComboBox *CB_TCPS_CONTENT_CLIENT_IP;
    QLabel *LE_TCPS_CONTENT_CLIENT_PORT;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *PB_TCPS_DISCONTENT_CLIENT;
    QTextEdit *TE_TCPS_SEND_CONTENT;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_6;
    QSpinBox *SB_TCPS_NUM_SEND;
    QPushButton *PB_TCPS_SEND;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_7;
    QLineEdit *LE_TCPS_LISTEN_PORT;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *PB_TCPS_LISTEN_PORT_CREATE;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_9;
    QLabel *TL_TCPS_LOCAL_PORT;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_8;
    QComboBox *CB_TCPS_LISTEN_PORT_LIST;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *PB_TCPS_LISTENING;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *PB_TCPS_LISTENED;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *PB_TCPS_LISTEN_PORT_DELETE;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *GB_TCP_SERVER_RECV;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_6;
    QTextEdit *TE_TCPS_RECV_CONTENT;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QLabel *TL_TCPS_LISTEN_COUNT;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QLabel *TL_TCPS_CLIENT_COUNT;
    QSpacerItem *verticalSpacer_7;
    QPushButton *PB_TCPS_START_RECV_CONTENT;
    QPushButton *PB_TCPS_STOP_RECV_CONTENT;
    QSpacerItem *verticalSpacer_4;
    QPushButton *PB_TCPS_RECV_CONTENT_CLEAR;
    QWidget *SW_TCP_CLIENT;
    QWidget *gridWidget_4;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_30;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_31;
    QVBoxLayout *verticalLayout_15;
    QTextEdit *TE_TCPC_SEND_CONTENT;
    QVBoxLayout *verticalLayout_16;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_16;
    QSpinBox *SB_TCPC_NUM_SEND;
    QPushButton *PB_TCPC_SEND;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout_23;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_17;
    QLineEdit *LE_TCPC_LOCAL_IP;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_18;
    QLabel *LE_TCPC_LOCAL_PORT;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_19;
    QLineEdit *LE_TCPC_TARGET_IP;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *PB_TCPC_CONNECT;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *PB_TCPC_DISCONNECT;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_22;
    QGroupBox *GB_TCP_SERVER_RECV_2;
    QHBoxLayout *horizontalLayout_27;
    QVBoxLayout *verticalLayout_12;
    QTextEdit *TE_TCPC_RECV_CONTENT;
    QVBoxLayout *verticalLayout_13;
    QPushButton *PB_TCPC_START_RECV_CONTENT;
    QPushButton *PB_TCPC_STOP_RECV_CONTENT;
    QSpacerItem *verticalSpacer_9;
    QPushButton *PB_TCPC_RECV_CONTENT_CLEAR;
    QWidget *SW_PDF_EXPORT;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_6;
    QListView *listView;

    void setupUi(QMainWindow *ExportScannerInfoClass)
    {
        if (ExportScannerInfoClass->objectName().isEmpty())
            ExportScannerInfoClass->setObjectName(QStringLiteral("ExportScannerInfoClass"));
        ExportScannerInfoClass->setWindowModality(Qt::ApplicationModal);
        ExportScannerInfoClass->resize(1090, 885);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ExportScannerInfoClass->sizePolicy().hasHeightForWidth());
        ExportScannerInfoClass->setSizePolicy(sizePolicy);
        ExportScannerInfoClass->setMinimumSize(QSize(1090, 885));
        ExportScannerInfoClass->setMouseTracking(true);
        ExportScannerInfoClass->setFocusPolicy(Qt::ClickFocus);
        ExportScannerInfoClass->setDocumentMode(false);
        centralWidget = new QWidget(ExportScannerInfoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        centralWidget->setFont(font);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("JetBrains Mono"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images.png\");"));

        horizontalLayout_2->addWidget(label);

        TL_PROMPT_OPERATION_STATUS = new QLabel(centralWidget);
        TL_PROMPT_OPERATION_STATUS->setObjectName(QStringLiteral("TL_PROMPT_OPERATION_STATUS"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font2.setPointSize(15);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        TL_PROMPT_OPERATION_STATUS->setFont(font2);
        TL_PROMPT_OPERATION_STATUS->setStyleSheet(QStringLiteral(""));
        TL_PROMPT_OPERATION_STATUS->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(TL_PROMPT_OPERATION_STATUS);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        widget_5->setMinimumSize(QSize(190, 800));
        widget_5->setMaximumSize(QSize(185, 800));
        verticalLayout_14 = new QVBoxLayout(widget_5);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        TL_TCP = new QLabel(widget_5);
        TL_TCP->setObjectName(QStringLiteral("TL_TCP"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TL_TCP->sizePolicy().hasHeightForWidth());
        TL_TCP->setSizePolicy(sizePolicy2);
        TL_TCP->setMinimumSize(QSize(0, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("JetBrains Mono ExtraBold"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        TL_TCP->setFont(font3);
        TL_TCP->setStyleSheet(QStringLiteral(""));

        verticalLayout_14->addWidget(TL_TCP);

        line_2 = new QFrame(widget_5);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_14->addWidget(line_2);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        TL_TCP_SERVER = new ClickableLabel(widget_5);
        TL_TCP_SERVER->setObjectName(QStringLiteral("TL_TCP_SERVER"));
        sizePolicy.setHeightForWidth(TL_TCP_SERVER->sizePolicy().hasHeightForWidth());
        TL_TCP_SERVER->setSizePolicy(sizePolicy);
        TL_TCP_SERVER->setMinimumSize(QSize(0, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        TL_TCP_SERVER->setFont(font4);
        TL_TCP_SERVER->setStyleSheet(QStringLiteral("QLabel:hover {color: #2980B9;}"));
        TL_TCP_SERVER->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_17->addWidget(TL_TCP_SERVER);

        TL_TCP_SERVER_ICON = new QLabel(widget_5);
        TL_TCP_SERVER_ICON->setObjectName(QStringLiteral("TL_TCP_SERVER_ICON"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TL_TCP_SERVER_ICON->sizePolicy().hasHeightForWidth());
        TL_TCP_SERVER_ICON->setSizePolicy(sizePolicy3);
        TL_TCP_SERVER_ICON->setMinimumSize(QSize(35, 30));

        horizontalLayout_17->addWidget(TL_TCP_SERVER_ICON);


        verticalLayout_14->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        TL_TCP_CLIENT = new ClickableLabel(widget_5);
        TL_TCP_CLIENT->setObjectName(QStringLiteral("TL_TCP_CLIENT"));
        sizePolicy.setHeightForWidth(TL_TCP_CLIENT->sizePolicy().hasHeightForWidth());
        TL_TCP_CLIENT->setSizePolicy(sizePolicy);
        TL_TCP_CLIENT->setMinimumSize(QSize(0, 30));
        TL_TCP_CLIENT->setFont(font);
        TL_TCP_CLIENT->setStyleSheet(QStringLiteral("QLabel:hover {color: #2980B9;}"));
        TL_TCP_CLIENT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(TL_TCP_CLIENT);

        TL_TCP_CLIENT_ICON = new QLabel(widget_5);
        TL_TCP_CLIENT_ICON->setObjectName(QStringLiteral("TL_TCP_CLIENT_ICON"));
        sizePolicy3.setHeightForWidth(TL_TCP_CLIENT_ICON->sizePolicy().hasHeightForWidth());
        TL_TCP_CLIENT_ICON->setSizePolicy(sizePolicy3);
        TL_TCP_CLIENT_ICON->setMinimumSize(QSize(35, 0));

        horizontalLayout_18->addWidget(TL_TCP_CLIENT_ICON);


        verticalLayout_14->addLayout(horizontalLayout_18);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_14->addItem(verticalSpacer);

        TL_PDF = new QLabel(widget_5);
        TL_PDF->setObjectName(QStringLiteral("TL_PDF"));
        sizePolicy.setHeightForWidth(TL_PDF->sizePolicy().hasHeightForWidth());
        TL_PDF->setSizePolicy(sizePolicy);
        TL_PDF->setMinimumSize(QSize(0, 40));
        QFont font5;
        font5.setFamily(QStringLiteral("JetBrains Mono ExtraBold"));
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        TL_PDF->setFont(font5);
        TL_PDF->setStyleSheet(QStringLiteral(""));
        TL_PDF->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_14->addWidget(TL_PDF);

        line = new QFrame(widget_5);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy4);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_14->addWidget(line);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        TL_PDF_EXPORT = new ClickableLabel(widget_5);
        TL_PDF_EXPORT->setObjectName(QStringLiteral("TL_PDF_EXPORT"));
        sizePolicy.setHeightForWidth(TL_PDF_EXPORT->sizePolicy().hasHeightForWidth());
        TL_PDF_EXPORT->setSizePolicy(sizePolicy);
        TL_PDF_EXPORT->setMinimumSize(QSize(0, 30));
        TL_PDF_EXPORT->setFont(font);
        TL_PDF_EXPORT->setStyleSheet(QStringLiteral("QLabel:hover {color: #2980B9;}"));
        TL_PDF_EXPORT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(TL_PDF_EXPORT);

        TL_PDF_EXPORT_ICON = new QLabel(widget_5);
        TL_PDF_EXPORT_ICON->setObjectName(QStringLiteral("TL_PDF_EXPORT_ICON"));
        sizePolicy3.setHeightForWidth(TL_PDF_EXPORT_ICON->sizePolicy().hasHeightForWidth());
        TL_PDF_EXPORT_ICON->setSizePolicy(sizePolicy3);
        TL_PDF_EXPORT_ICON->setMinimumSize(QSize(35, 0));

        horizontalLayout_19->addWidget(TL_PDF_EXPORT_ICON);


        verticalLayout_14->addLayout(horizontalLayout_19);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_14->addItem(verticalSpacer_2);

        TL_FTP = new QLabel(widget_5);
        TL_FTP->setObjectName(QStringLiteral("TL_FTP"));
        sizePolicy.setHeightForWidth(TL_FTP->sizePolicy().hasHeightForWidth());
        TL_FTP->setSizePolicy(sizePolicy);
        TL_FTP->setMinimumSize(QSize(0, 40));
        QFont font6;
        font6.setFamily(QStringLiteral("JetBrains Mono ExtraBold"));
        font6.setPointSize(11);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        TL_FTP->setFont(font6);
        TL_FTP->setStyleSheet(QStringLiteral(""));
        TL_FTP->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_14->addWidget(TL_FTP);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        TL_FTP_SERVER = new ClickableLabel(widget_5);
        TL_FTP_SERVER->setObjectName(QStringLiteral("TL_FTP_SERVER"));
        sizePolicy.setHeightForWidth(TL_FTP_SERVER->sizePolicy().hasHeightForWidth());
        TL_FTP_SERVER->setSizePolicy(sizePolicy);
        TL_FTP_SERVER->setMinimumSize(QSize(0, 30));
        TL_FTP_SERVER->setFont(font);
        TL_FTP_SERVER->setStyleSheet(QStringLiteral("QLabel:hover {color: #2980B9;}"));
        TL_FTP_SERVER->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_20->addWidget(TL_FTP_SERVER);

        TL_FTP_SERVER_ICON = new QLabel(widget_5);
        TL_FTP_SERVER_ICON->setObjectName(QStringLiteral("TL_FTP_SERVER_ICON"));
        sizePolicy3.setHeightForWidth(TL_FTP_SERVER_ICON->sizePolicy().hasHeightForWidth());
        TL_FTP_SERVER_ICON->setSizePolicy(sizePolicy3);
        TL_FTP_SERVER_ICON->setMinimumSize(QSize(35, 0));

        horizontalLayout_20->addWidget(TL_FTP_SERVER_ICON);


        verticalLayout_14->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        TL_FTP_CLIENT = new ClickableLabel(widget_5);
        TL_FTP_CLIENT->setObjectName(QStringLiteral("TL_FTP_CLIENT"));
        sizePolicy.setHeightForWidth(TL_FTP_CLIENT->sizePolicy().hasHeightForWidth());
        TL_FTP_CLIENT->setSizePolicy(sizePolicy);
        TL_FTP_CLIENT->setMinimumSize(QSize(0, 30));
        TL_FTP_CLIENT->setFont(font);
        TL_FTP_CLIENT->setStyleSheet(QStringLiteral("QLabel:hover {color: #2980B9;}"));
        TL_FTP_CLIENT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_21->addWidget(TL_FTP_CLIENT);

        TL_FTP_CLIENT_ICON = new QLabel(widget_5);
        TL_FTP_CLIENT_ICON->setObjectName(QStringLiteral("TL_FTP_CLIENT_ICON"));
        sizePolicy3.setHeightForWidth(TL_FTP_CLIENT_ICON->sizePolicy().hasHeightForWidth());
        TL_FTP_CLIENT_ICON->setSizePolicy(sizePolicy3);
        TL_FTP_CLIENT_ICON->setMinimumSize(QSize(35, 0));

        horizontalLayout_21->addWidget(TL_FTP_CLIENT_ICON);


        verticalLayout_14->addLayout(horizontalLayout_21);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_3);


        verticalLayout->addWidget(widget_5);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        STACKWIDGET = new QStackedWidget(centralWidget);
        STACKWIDGET->setObjectName(QStringLiteral("STACKWIDGET"));
        sizePolicy.setHeightForWidth(STACKWIDGET->sizePolicy().hasHeightForWidth());
        STACKWIDGET->setSizePolicy(sizePolicy);
        STACKWIDGET->setMinimumSize(QSize(0, 0));
        STACKWIDGET->setFont(font);
        SW_FTP_SERVER = new QWidget();
        SW_FTP_SERVER->setObjectName(QStringLiteral("SW_FTP_SERVER"));
        sizePolicy1.setHeightForWidth(SW_FTP_SERVER->sizePolicy().hasHeightForWidth());
        SW_FTP_SERVER->setSizePolicy(sizePolicy1);
        gridLayoutWidget = new QWidget(SW_FTP_SERVER);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 561, 571));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        gridLayout_2->addLayout(verticalLayout_3, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy5);

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy5.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy5);

        horizontalLayout_8->addWidget(lineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy5.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy5);

        horizontalLayout_8->addWidget(lineEdit_3);


        verticalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout_4->addLayout(verticalLayout_7);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        groupBox_3 = new QGroupBox(gridLayoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayoutWidget_5 = new QWidget(groupBox_3);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(0, 20, 411, 131));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBox_3 = new QCheckBox(verticalLayoutWidget_5);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        verticalLayout_5->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(verticalLayoutWidget_5);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout_5->addWidget(checkBox_2);


        horizontalLayout_7->addWidget(groupBox_3);

        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 20, 411, 131));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(groupBox);


        verticalLayout_4->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);

        STACKWIDGET->addWidget(SW_FTP_SERVER);
        SW_FTP_CLIENT = new QWidget();
        SW_FTP_CLIENT->setObjectName(QStringLiteral("SW_FTP_CLIENT"));
        sizePolicy1.setHeightForWidth(SW_FTP_CLIENT->sizePolicy().hasHeightForWidth());
        SW_FTP_CLIENT->setSizePolicy(sizePolicy1);
        gridLayoutWidget_2 = new QWidget(SW_FTP_CLIENT);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 551, 501));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(gridLayoutWidget_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout_3->addWidget(radioButton, 0, 0, 1, 1);

        STACKWIDGET->addWidget(SW_FTP_CLIENT);
        SW_TCP_SERVER = new QWidget();
        SW_TCP_SERVER->setObjectName(QStringLiteral("SW_TCP_SERVER"));
        sizePolicy.setHeightForWidth(SW_TCP_SERVER->sizePolicy().hasHeightForWidth());
        SW_TCP_SERVER->setSizePolicy(sizePolicy);
        SW_TCP_SERVER->setMinimumSize(QSize(870, 0));
        SW_TCP_SERVER->setFont(font);
        gridWidget_3 = new QWidget(SW_TCP_SERVER);
        gridWidget_3->setObjectName(QStringLiteral("gridWidget_3"));
        gridWidget_3->setGeometry(QRect(0, 0, 861, 821));
        sizePolicy.setHeightForWidth(gridWidget_3->sizePolicy().hasHeightForWidth());
        gridWidget_3->setSizePolicy(sizePolicy);
        gridWidget_3->setMinimumSize(QSize(850, 800));
        gridWidget_3->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_4 = new QGridLayout(gridWidget_3);
        gridLayout_4->setSpacing(7);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        groupBox_2 = new QGroupBox(gridWidget_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(750, 200));
        horizontalLayout_13 = new QHBoxLayout(groupBox_2);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        CHB_TCPS_ALL_CLIENT = new QCheckBox(groupBox_2);
        CHB_TCPS_ALL_CLIENT->setObjectName(QStringLiteral("CHB_TCPS_ALL_CLIENT"));

        horizontalLayout_4->addWidget(CHB_TCPS_ALL_CLIENT);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(label_10);

        CB_TCPS_CONTENT_CLIENT_IP = new QComboBox(groupBox_2);
        CB_TCPS_CONTENT_CLIENT_IP->setObjectName(QStringLiteral("CB_TCPS_CONTENT_CLIENT_IP"));
        CB_TCPS_CONTENT_CLIENT_IP->setMinimumSize(QSize(165, 30));

        horizontalLayout_4->addWidget(CB_TCPS_CONTENT_CLIENT_IP);

        LE_TCPS_CONTENT_CLIENT_PORT = new QLabel(groupBox_2);
        LE_TCPS_CONTENT_CLIENT_PORT->setObjectName(QStringLiteral("LE_TCPS_CONTENT_CLIENT_PORT"));
        sizePolicy.setHeightForWidth(LE_TCPS_CONTENT_CLIENT_PORT->sizePolicy().hasHeightForWidth());
        LE_TCPS_CONTENT_CLIENT_PORT->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(LE_TCPS_CONTENT_CLIENT_PORT);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        PB_TCPS_DISCONTENT_CLIENT = new QPushButton(groupBox_2);
        PB_TCPS_DISCONTENT_CLIENT->setObjectName(QStringLiteral("PB_TCPS_DISCONTENT_CLIENT"));
        PB_TCPS_DISCONTENT_CLIENT->setMinimumSize(QSize(90, 35));
        PB_TCPS_DISCONTENT_CLIENT->setFont(font);
        PB_TCPS_DISCONTENT_CLIENT->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/disconnect.png\");"));

        horizontalLayout_4->addWidget(PB_TCPS_DISCONTENT_CLIENT);


        verticalLayout_10->addLayout(horizontalLayout_4);

        TE_TCPS_SEND_CONTENT = new QTextEdit(groupBox_2);
        TE_TCPS_SEND_CONTENT->setObjectName(QStringLiteral("TE_TCPS_SEND_CONTENT"));
        sizePolicy2.setHeightForWidth(TE_TCPS_SEND_CONTENT->sizePolicy().hasHeightForWidth());
        TE_TCPS_SEND_CONTENT->setSizePolicy(sizePolicy2);
        TE_TCPS_SEND_CONTENT->setMinimumSize(QSize(660, 0));
        TE_TCPS_SEND_CONTENT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_10->addWidget(TE_TCPS_SEND_CONTENT);


        horizontalLayout_13->addLayout(verticalLayout_10);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_6);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_9->addWidget(label_6);

        SB_TCPS_NUM_SEND = new QSpinBox(groupBox_2);
        SB_TCPS_NUM_SEND->setObjectName(QStringLiteral("SB_TCPS_NUM_SEND"));
        SB_TCPS_NUM_SEND->setMinimumSize(QSize(0, 0));
        SB_TCPS_NUM_SEND->setMinimum(1);
        SB_TCPS_NUM_SEND->setMaximum(20);

        verticalLayout_9->addWidget(SB_TCPS_NUM_SEND);

        PB_TCPS_SEND = new QPushButton(groupBox_2);
        PB_TCPS_SEND->setObjectName(QStringLiteral("PB_TCPS_SEND"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(PB_TCPS_SEND->sizePolicy().hasHeightForWidth());
        PB_TCPS_SEND->setSizePolicy(sizePolicy6);
        PB_TCPS_SEND->setMinimumSize(QSize(0, 35));
        QFont font7;
        PB_TCPS_SEND->setFont(font7);
        PB_TCPS_SEND->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/send.png\");"));

        verticalLayout_9->addWidget(PB_TCPS_SEND);

        verticalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_5);


        horizontalLayout_13->addLayout(verticalLayout_9);


        horizontalLayout_9->addWidget(groupBox_2);


        gridLayout_4->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        groupBox_4 = new QGroupBox(gridWidget_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setMinimumSize(QSize(0, 0));
        verticalLayout_11 = new QVBoxLayout(groupBox_4);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(label_7);

        LE_TCPS_LISTEN_PORT = new QLineEdit(groupBox_4);
        LE_TCPS_LISTEN_PORT->setObjectName(QStringLiteral("LE_TCPS_LISTEN_PORT"));
        sizePolicy6.setHeightForWidth(LE_TCPS_LISTEN_PORT->sizePolicy().hasHeightForWidth());
        LE_TCPS_LISTEN_PORT->setSizePolicy(sizePolicy6);
        LE_TCPS_LISTEN_PORT->setMinimumSize(QSize(165, 0));

        horizontalLayout_16->addWidget(LE_TCPS_LISTEN_PORT);

        horizontalSpacer_8 = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_8);

        PB_TCPS_LISTEN_PORT_CREATE = new QPushButton(groupBox_4);
        PB_TCPS_LISTEN_PORT_CREATE->setObjectName(QStringLiteral("PB_TCPS_LISTEN_PORT_CREATE"));
        PB_TCPS_LISTEN_PORT_CREATE->setMinimumSize(QSize(90, 35));
        PB_TCPS_LISTEN_PORT_CREATE->setFont(font7);
        PB_TCPS_LISTEN_PORT_CREATE->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/create.png\");"));

        horizontalLayout_16->addWidget(PB_TCPS_LISTEN_PORT_CREATE);

        horizontalSpacer_5 = new QSpacerItem(180, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_5);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_16->addWidget(label_9);

        TL_TCPS_LOCAL_PORT = new QLabel(groupBox_4);
        TL_TCPS_LOCAL_PORT->setObjectName(QStringLiteral("TL_TCPS_LOCAL_PORT"));
        sizePolicy2.setHeightForWidth(TL_TCPS_LOCAL_PORT->sizePolicy().hasHeightForWidth());
        TL_TCPS_LOCAL_PORT->setSizePolicy(sizePolicy2);
        TL_TCPS_LOCAL_PORT->setMinimumSize(QSize(0, 0));

        horizontalLayout_16->addWidget(TL_TCPS_LOCAL_PORT);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);


        verticalLayout_11->addLayout(horizontalLayout_16);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        horizontalLayout_14->addWidget(label_8);

        CB_TCPS_LISTEN_PORT_LIST = new QComboBox(groupBox_4);
        CB_TCPS_LISTEN_PORT_LIST->setObjectName(QStringLiteral("CB_TCPS_LISTEN_PORT_LIST"));
        sizePolicy5.setHeightForWidth(CB_TCPS_LISTEN_PORT_LIST->sizePolicy().hasHeightForWidth());
        CB_TCPS_LISTEN_PORT_LIST->setSizePolicy(sizePolicy5);
        CB_TCPS_LISTEN_PORT_LIST->setMinimumSize(QSize(165, 0));
        CB_TCPS_LISTEN_PORT_LIST->setInsertPolicy(QComboBox::NoInsert);
        CB_TCPS_LISTEN_PORT_LIST->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        CB_TCPS_LISTEN_PORT_LIST->setDuplicatesEnabled(false);

        horizontalLayout_14->addWidget(CB_TCPS_LISTEN_PORT_LIST);

        horizontalSpacer_7 = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_7);

        PB_TCPS_LISTENING = new QPushButton(groupBox_4);
        PB_TCPS_LISTENING->setObjectName(QStringLiteral("PB_TCPS_LISTENING"));
        sizePolicy6.setHeightForWidth(PB_TCPS_LISTENING->sizePolicy().hasHeightForWidth());
        PB_TCPS_LISTENING->setSizePolicy(sizePolicy6);
        PB_TCPS_LISTENING->setMinimumSize(QSize(90, 35));
        PB_TCPS_LISTENING->setFont(font7);
        PB_TCPS_LISTENING->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/listen.png\");"));

        horizontalLayout_14->addWidget(PB_TCPS_LISTENING);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_6);

        PB_TCPS_LISTENED = new QPushButton(groupBox_4);
        PB_TCPS_LISTENED->setObjectName(QStringLiteral("PB_TCPS_LISTENED"));
        sizePolicy5.setHeightForWidth(PB_TCPS_LISTENED->sizePolicy().hasHeightForWidth());
        PB_TCPS_LISTENED->setSizePolicy(sizePolicy5);
        PB_TCPS_LISTENED->setMinimumSize(QSize(90, 35));
        PB_TCPS_LISTENED->setFont(font7);
        PB_TCPS_LISTENED->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/warn.png\");"));

        horizontalLayout_14->addWidget(PB_TCPS_LISTENED);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_10);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_12);

        PB_TCPS_LISTEN_PORT_DELETE = new QPushButton(groupBox_4);
        PB_TCPS_LISTEN_PORT_DELETE->setObjectName(QStringLiteral("PB_TCPS_LISTEN_PORT_DELETE"));
        PB_TCPS_LISTEN_PORT_DELETE->setMinimumSize(QSize(90, 35));
        PB_TCPS_LISTEN_PORT_DELETE->setFont(font4);
        PB_TCPS_LISTEN_PORT_DELETE->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/delete.png\");"));

        horizontalLayout_14->addWidget(PB_TCPS_LISTEN_PORT_DELETE);


        verticalLayout_11->addLayout(horizontalLayout_14);


        horizontalLayout_11->addWidget(groupBox_4);


        gridLayout_4->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        GB_TCP_SERVER_RECV = new QGroupBox(gridWidget_3);
        GB_TCP_SERVER_RECV->setObjectName(QStringLiteral("GB_TCP_SERVER_RECV"));
        sizePolicy1.setHeightForWidth(GB_TCP_SERVER_RECV->sizePolicy().hasHeightForWidth());
        GB_TCP_SERVER_RECV->setSizePolicy(sizePolicy1);
        GB_TCP_SERVER_RECV->setMinimumSize(QSize(750, 400));
        horizontalLayout_12 = new QHBoxLayout(GB_TCP_SERVER_RECV);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        TE_TCPS_RECV_CONTENT = new QTextEdit(GB_TCP_SERVER_RECV);
        TE_TCPS_RECV_CONTENT->setObjectName(QStringLiteral("TE_TCPS_RECV_CONTENT"));
        sizePolicy1.setHeightForWidth(TE_TCPS_RECV_CONTENT->sizePolicy().hasHeightForWidth());
        TE_TCPS_RECV_CONTENT->setSizePolicy(sizePolicy1);
        TE_TCPS_RECV_CONTENT->setMinimumSize(QSize(660, 0));
        TE_TCPS_RECV_CONTENT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        TE_TCPS_RECV_CONTENT->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TE_TCPS_RECV_CONTENT->setTabChangesFocus(false);
        TE_TCPS_RECV_CONTENT->setReadOnly(true);

        verticalLayout_6->addWidget(TE_TCPS_RECV_CONTENT);


        horizontalLayout_12->addLayout(verticalLayout_6);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_13 = new QLabel(GB_TCP_SERVER_RECV);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_6->addWidget(label_13);

        TL_TCPS_LISTEN_COUNT = new QLabel(GB_TCP_SERVER_RECV);
        TL_TCPS_LISTEN_COUNT->setObjectName(QStringLiteral("TL_TCPS_LISTEN_COUNT"));

        horizontalLayout_6->addWidget(TL_TCPS_LISTEN_COUNT);


        verticalLayout_8->addLayout(horizontalLayout_6);

        line_3 = new QFrame(GB_TCP_SERVER_RECV);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_11 = new QLabel(GB_TCP_SERVER_RECV);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_11);

        TL_TCPS_CLIENT_COUNT = new QLabel(GB_TCP_SERVER_RECV);
        TL_TCPS_CLIENT_COUNT->setObjectName(QStringLiteral("TL_TCPS_CLIENT_COUNT"));
        sizePolicy.setHeightForWidth(TL_TCPS_CLIENT_COUNT->sizePolicy().hasHeightForWidth());
        TL_TCPS_CLIENT_COUNT->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(TL_TCPS_CLIENT_COUNT);


        verticalLayout_8->addLayout(horizontalLayout_3);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_7);

        PB_TCPS_START_RECV_CONTENT = new QPushButton(GB_TCP_SERVER_RECV);
        PB_TCPS_START_RECV_CONTENT->setObjectName(QStringLiteral("PB_TCPS_START_RECV_CONTENT"));
        PB_TCPS_START_RECV_CONTENT->setMinimumSize(QSize(0, 35));
        PB_TCPS_START_RECV_CONTENT->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/continue.png\");"));

        verticalLayout_8->addWidget(PB_TCPS_START_RECV_CONTENT);

        PB_TCPS_STOP_RECV_CONTENT = new QPushButton(GB_TCP_SERVER_RECV);
        PB_TCPS_STOP_RECV_CONTENT->setObjectName(QStringLiteral("PB_TCPS_STOP_RECV_CONTENT"));
        PB_TCPS_STOP_RECV_CONTENT->setMinimumSize(QSize(0, 35));
        PB_TCPS_STOP_RECV_CONTENT->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/pause.png\");"));

        verticalLayout_8->addWidget(PB_TCPS_STOP_RECV_CONTENT);

        verticalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_4);

        PB_TCPS_RECV_CONTENT_CLEAR = new QPushButton(GB_TCP_SERVER_RECV);
        PB_TCPS_RECV_CONTENT_CLEAR->setObjectName(QStringLiteral("PB_TCPS_RECV_CONTENT_CLEAR"));
        sizePolicy6.setHeightForWidth(PB_TCPS_RECV_CONTENT_CLEAR->sizePolicy().hasHeightForWidth());
        PB_TCPS_RECV_CONTENT_CLEAR->setSizePolicy(sizePolicy6);
        PB_TCPS_RECV_CONTENT_CLEAR->setMinimumSize(QSize(0, 35));
        PB_TCPS_RECV_CONTENT_CLEAR->setBaseSize(QSize(0, 0));
        PB_TCPS_RECV_CONTENT_CLEAR->setLayoutDirection(Qt::LeftToRight);
        PB_TCPS_RECV_CONTENT_CLEAR->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/clear.png\");"));
        PB_TCPS_RECV_CONTENT_CLEAR->setInputMethodHints(Qt::ImhNone);
        PB_TCPS_RECV_CONTENT_CLEAR->setCheckable(false);
        PB_TCPS_RECV_CONTENT_CLEAR->setAutoDefault(false);
        PB_TCPS_RECV_CONTENT_CLEAR->setFlat(false);

        verticalLayout_8->addWidget(PB_TCPS_RECV_CONTENT_CLEAR);


        horizontalLayout_12->addLayout(verticalLayout_8);


        horizontalLayout_10->addWidget(GB_TCP_SERVER_RECV);


        gridLayout_4->addLayout(horizontalLayout_10, 1, 0, 1, 1);

        STACKWIDGET->addWidget(SW_TCP_SERVER);
        SW_TCP_CLIENT = new QWidget();
        SW_TCP_CLIENT->setObjectName(QStringLiteral("SW_TCP_CLIENT"));
        sizePolicy1.setHeightForWidth(SW_TCP_CLIENT->sizePolicy().hasHeightForWidth());
        SW_TCP_CLIENT->setSizePolicy(sizePolicy1);
        gridWidget_4 = new QWidget(SW_TCP_CLIENT);
        gridWidget_4->setObjectName(QStringLiteral("gridWidget_4"));
        gridWidget_4->setGeometry(QRect(0, 0, 861, 821));
        gridLayout_5 = new QGridLayout(gridWidget_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        groupBox_6 = new QGroupBox(gridWidget_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        sizePolicy1.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy1);
        groupBox_6->setMinimumSize(QSize(750, 200));
        horizontalLayout_31 = new QHBoxLayout(groupBox_6);
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        TE_TCPC_SEND_CONTENT = new QTextEdit(groupBox_6);
        TE_TCPC_SEND_CONTENT->setObjectName(QStringLiteral("TE_TCPC_SEND_CONTENT"));
        sizePolicy2.setHeightForWidth(TE_TCPC_SEND_CONTENT->sizePolicy().hasHeightForWidth());
        TE_TCPC_SEND_CONTENT->setSizePolicy(sizePolicy2);
        TE_TCPC_SEND_CONTENT->setMinimumSize(QSize(630, 0));
        TE_TCPC_SEND_CONTENT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_15->addWidget(TE_TCPC_SEND_CONTENT);


        horizontalLayout_31->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalSpacer_10 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_16->addItem(verticalSpacer_10);

        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_16->addWidget(label_16);

        SB_TCPC_NUM_SEND = new QSpinBox(groupBox_6);
        SB_TCPC_NUM_SEND->setObjectName(QStringLiteral("SB_TCPC_NUM_SEND"));
        SB_TCPC_NUM_SEND->setMinimumSize(QSize(0, 0));

        verticalLayout_16->addWidget(SB_TCPC_NUM_SEND);

        PB_TCPC_SEND = new QPushButton(groupBox_6);
        PB_TCPC_SEND->setObjectName(QStringLiteral("PB_TCPC_SEND"));
        sizePolicy6.setHeightForWidth(PB_TCPC_SEND->sizePolicy().hasHeightForWidth());
        PB_TCPC_SEND->setSizePolicy(sizePolicy6);
        PB_TCPC_SEND->setMinimumSize(QSize(0, 35));
        PB_TCPC_SEND->setFont(font7);
        PB_TCPC_SEND->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/send.png\");"));

        verticalLayout_16->addWidget(PB_TCPC_SEND);

        verticalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_11);


        horizontalLayout_31->addLayout(verticalLayout_16);


        horizontalLayout_30->addWidget(groupBox_6);


        horizontalLayout_15->addLayout(horizontalLayout_30);


        gridLayout_5->addLayout(horizontalLayout_15, 4, 0, 1, 1);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        groupBox_7 = new QGroupBox(gridWidget_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        sizePolicy1.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy1);
        groupBox_7->setMinimumSize(QSize(0, 0));
        verticalLayout_17 = new QVBoxLayout(groupBox_7);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);

        horizontalLayout_33->addWidget(label_17);

        LE_TCPC_LOCAL_IP = new QLineEdit(groupBox_7);
        LE_TCPC_LOCAL_IP->setObjectName(QStringLiteral("LE_TCPC_LOCAL_IP"));
        sizePolicy6.setHeightForWidth(LE_TCPC_LOCAL_IP->sizePolicy().hasHeightForWidth());
        LE_TCPC_LOCAL_IP->setSizePolicy(sizePolicy6);
        LE_TCPC_LOCAL_IP->setMinimumSize(QSize(165, 0));

        horizontalLayout_33->addWidget(LE_TCPC_LOCAL_IP);

        horizontalSpacer_14 = new QSpacerItem(30, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_14);

        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_33->addWidget(label_18);

        LE_TCPC_LOCAL_PORT = new QLabel(groupBox_7);
        LE_TCPC_LOCAL_PORT->setObjectName(QStringLiteral("LE_TCPC_LOCAL_PORT"));
        sizePolicy2.setHeightForWidth(LE_TCPC_LOCAL_PORT->sizePolicy().hasHeightForWidth());
        LE_TCPC_LOCAL_PORT->setSizePolicy(sizePolicy2);
        LE_TCPC_LOCAL_PORT->setMinimumSize(QSize(0, 0));

        horizontalLayout_33->addWidget(LE_TCPC_LOCAL_PORT);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_16);


        verticalLayout_17->addLayout(horizontalLayout_33);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        label_19 = new QLabel(groupBox_7);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);

        horizontalLayout_34->addWidget(label_19);

        LE_TCPC_TARGET_IP = new QLineEdit(groupBox_7);
        LE_TCPC_TARGET_IP->setObjectName(QStringLiteral("LE_TCPC_TARGET_IP"));
        sizePolicy6.setHeightForWidth(LE_TCPC_TARGET_IP->sizePolicy().hasHeightForWidth());
        LE_TCPC_TARGET_IP->setSizePolicy(sizePolicy6);
        LE_TCPC_TARGET_IP->setMinimumSize(QSize(165, 0));

        horizontalLayout_34->addWidget(LE_TCPC_TARGET_IP);

        horizontalSpacer_17 = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_17);

        PB_TCPC_CONNECT = new QPushButton(groupBox_7);
        PB_TCPC_CONNECT->setObjectName(QStringLiteral("PB_TCPC_CONNECT"));
        PB_TCPC_CONNECT->setMinimumSize(QSize(90, 35));
        PB_TCPC_CONNECT->setFont(font7);
        PB_TCPC_CONNECT->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/c_connect.png\");"));

        horizontalLayout_34->addWidget(PB_TCPC_CONNECT);

        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_13);

        PB_TCPC_DISCONNECT = new QPushButton(groupBox_7);
        PB_TCPC_DISCONNECT->setObjectName(QStringLiteral("PB_TCPC_DISCONNECT"));
        PB_TCPC_DISCONNECT->setMinimumSize(QSize(90, 35));
        PB_TCPC_DISCONNECT->setFont(font4);
        PB_TCPC_DISCONNECT->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/c_disconnect.png\");"));

        horizontalLayout_34->addWidget(PB_TCPC_DISCONNECT);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_20);


        verticalLayout_17->addLayout(horizontalLayout_34);


        horizontalLayout_23->addWidget(groupBox_7);


        gridLayout_5->addLayout(horizontalLayout_23, 2, 0, 1, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        GB_TCP_SERVER_RECV_2 = new QGroupBox(gridWidget_4);
        GB_TCP_SERVER_RECV_2->setObjectName(QStringLiteral("GB_TCP_SERVER_RECV_2"));
        sizePolicy1.setHeightForWidth(GB_TCP_SERVER_RECV_2->sizePolicy().hasHeightForWidth());
        GB_TCP_SERVER_RECV_2->setSizePolicy(sizePolicy1);
        GB_TCP_SERVER_RECV_2->setMinimumSize(QSize(750, 400));
        horizontalLayout_27 = new QHBoxLayout(GB_TCP_SERVER_RECV_2);
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        TE_TCPC_RECV_CONTENT = new QTextEdit(GB_TCP_SERVER_RECV_2);
        TE_TCPC_RECV_CONTENT->setObjectName(QStringLiteral("TE_TCPC_RECV_CONTENT"));
        sizePolicy1.setHeightForWidth(TE_TCPC_RECV_CONTENT->sizePolicy().hasHeightForWidth());
        TE_TCPC_RECV_CONTENT->setSizePolicy(sizePolicy1);
        TE_TCPC_RECV_CONTENT->setMinimumSize(QSize(630, 0));
        TE_TCPC_RECV_CONTENT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        TE_TCPC_RECV_CONTENT->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TE_TCPC_RECV_CONTENT->setTabChangesFocus(false);
        TE_TCPC_RECV_CONTENT->setReadOnly(true);

        verticalLayout_12->addWidget(TE_TCPC_RECV_CONTENT);


        horizontalLayout_27->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        PB_TCPC_START_RECV_CONTENT = new QPushButton(GB_TCP_SERVER_RECV_2);
        PB_TCPC_START_RECV_CONTENT->setObjectName(QStringLiteral("PB_TCPC_START_RECV_CONTENT"));
        PB_TCPC_START_RECV_CONTENT->setMinimumSize(QSize(0, 35));
        PB_TCPC_START_RECV_CONTENT->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/continue.png\");"));

        verticalLayout_13->addWidget(PB_TCPC_START_RECV_CONTENT);

        PB_TCPC_STOP_RECV_CONTENT = new QPushButton(GB_TCP_SERVER_RECV_2);
        PB_TCPC_STOP_RECV_CONTENT->setObjectName(QStringLiteral("PB_TCPC_STOP_RECV_CONTENT"));
        PB_TCPC_STOP_RECV_CONTENT->setMinimumSize(QSize(0, 35));
        PB_TCPC_STOP_RECV_CONTENT->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/pause.png\");"));

        verticalLayout_13->addWidget(PB_TCPC_STOP_RECV_CONTENT);

        verticalSpacer_9 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_9);

        PB_TCPC_RECV_CONTENT_CLEAR = new QPushButton(GB_TCP_SERVER_RECV_2);
        PB_TCPC_RECV_CONTENT_CLEAR->setObjectName(QStringLiteral("PB_TCPC_RECV_CONTENT_CLEAR"));
        sizePolicy6.setHeightForWidth(PB_TCPC_RECV_CONTENT_CLEAR->sizePolicy().hasHeightForWidth());
        PB_TCPC_RECV_CONTENT_CLEAR->setSizePolicy(sizePolicy6);
        PB_TCPC_RECV_CONTENT_CLEAR->setMinimumSize(QSize(0, 35));
        PB_TCPC_RECV_CONTENT_CLEAR->setBaseSize(QSize(0, 0));
        PB_TCPC_RECV_CONTENT_CLEAR->setLayoutDirection(Qt::LeftToRight);
        PB_TCPC_RECV_CONTENT_CLEAR->setStyleSheet(QStringLiteral("qproperty-icon: url(\"./images/clear.png\");"));
        PB_TCPC_RECV_CONTENT_CLEAR->setInputMethodHints(Qt::ImhNone);
        PB_TCPC_RECV_CONTENT_CLEAR->setCheckable(false);
        PB_TCPC_RECV_CONTENT_CLEAR->setAutoDefault(false);
        PB_TCPC_RECV_CONTENT_CLEAR->setFlat(false);

        verticalLayout_13->addWidget(PB_TCPC_RECV_CONTENT_CLEAR);


        horizontalLayout_27->addLayout(verticalLayout_13);


        horizontalLayout_22->addWidget(GB_TCP_SERVER_RECV_2);


        gridLayout_5->addLayout(horizontalLayout_22, 3, 0, 1, 1);

        STACKWIDGET->addWidget(SW_TCP_CLIENT);
        SW_PDF_EXPORT = new QWidget();
        SW_PDF_EXPORT->setObjectName(QStringLiteral("SW_PDF_EXPORT"));
        sizePolicy1.setHeightForWidth(SW_PDF_EXPORT->sizePolicy().hasHeightForWidth());
        SW_PDF_EXPORT->setSizePolicy(sizePolicy1);
        gridLayoutWidget_5 = new QWidget(SW_PDF_EXPORT);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(60, 60, 631, 491));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        listView = new QListView(gridLayoutWidget_5);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout_6->addWidget(listView, 0, 0, 1, 1);

        STACKWIDGET->addWidget(SW_PDF_EXPORT);

        verticalLayout_2->addWidget(STACKWIDGET);


        horizontalLayout_5->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        ExportScannerInfoClass->setCentralWidget(centralWidget);

        retranslateUi(ExportScannerInfoClass);
        QObject::connect(PB_TCPS_LISTEN_PORT_CREATE, SIGNAL(clicked()), ExportScannerInfoClass, SLOT(onClicked_PB_TCPS_LISTEN_PORT_CREATE()));
        QObject::connect(PB_TCPS_LISTENING, SIGNAL(clicked()), ExportScannerInfoClass, SLOT(onClicked_PB_TCPS_LISTENING()));
        QObject::connect(PB_TCPS_LISTENED, SIGNAL(clicked()), ExportScannerInfoClass, SLOT(onClicked_PB_TCPS_LISTENED()));
        QObject::connect(PB_TCPS_LISTEN_PORT_DELETE, SIGNAL(clicked()), ExportScannerInfoClass, SLOT(onClicked_PB_TCPS_LISTEN_PORT_DELETE()));
        QObject::connect(PB_TCPS_RECV_CONTENT_CLEAR, SIGNAL(clicked()), TE_TCPS_RECV_CONTENT, SLOT(clear()));
        QObject::connect(CB_TCPS_LISTEN_PORT_LIST, SIGNAL(currentIndexChanged(QString)), ExportScannerInfoClass, SLOT(onCurrentIndexChanged_CB_TCPS_LISTEN_PORT_LIST()));
        QObject::connect(CB_TCPS_CONTENT_CLIENT_IP, SIGNAL(currentIndexChanged(QString)), ExportScannerInfoClass, SLOT(onCurrentindexChanged_CB_TCPS_CONTENT_CLIENT_IP()));
        QObject::connect(PB_TCPS_START_RECV_CONTENT, SIGNAL(clicked()), ExportScannerInfoClass, SLOT(onClicked_PB_TCPS_START_RECV_CONTENT()));
        QObject::connect(PB_TCPS_STOP_RECV_CONTENT, SIGNAL(clicked()), ExportScannerInfoClass, SLOT(onClicked_PB_TCPS_STOP_RECV_CONTENT()));
        QObject::connect(PB_TCPS_DISCONTENT_CLIENT, SIGNAL(clicked()), ExportScannerInfoClass, SLOT(onClicked_PB_TCPS_DISCONNECT_CLIENT()));
        QObject::connect(PB_TCPS_SEND, SIGNAL(clicked()), ExportScannerInfoClass, SLOT(onClicked_PB_TCPS_SEND_CLIENT()));
        QObject::connect(CHB_TCPS_ALL_CLIENT, SIGNAL(stateChanged(int)), ExportScannerInfoClass, SLOT(onStateChanged_CHB_TCPS_ALL_CLIENT()));

        STACKWIDGET->setCurrentIndex(3);
        PB_TCPS_RECV_CONTENT_CLEAR->setDefault(false);
        PB_TCPC_RECV_CONTENT_CLEAR->setDefault(false);


        QMetaObject::connectSlotsByName(ExportScannerInfoClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExportScannerInfoClass)
    {
        ExportScannerInfoClass->setWindowTitle(QApplication::translate("ExportScannerInfoClass", "ExportScannerInfo", Q_NULLPTR));
        label->setText(QApplication::translate("ExportScannerInfoClass", "\344\277\241\346\201\257\344\274\240\350\276\223\345\212\251\346\211\213", Q_NULLPTR));
        TL_PROMPT_OPERATION_STATUS->setText(QApplication::translate("ExportScannerInfoClass", "\346\223\215\344\275\234\346\240\207\347\255\276", Q_NULLPTR));
        TL_TCP->setText(QApplication::translate("ExportScannerInfoClass", " TCP \350\256\276\347\275\256", Q_NULLPTR));
        TL_TCP_SERVER->setText(QApplication::translate("ExportScannerInfoClass", "tcp \346\234\215\345\212\241\347\253\257  ", Q_NULLPTR));
        TL_TCP_SERVER_ICON->setText(QString());
        TL_TCP_CLIENT->setText(QApplication::translate("ExportScannerInfoClass", "tcp \345\256\242\346\210\267\347\253\257  ", Q_NULLPTR));
        TL_TCP_CLIENT_ICON->setText(QString());
        TL_PDF->setText(QApplication::translate("ExportScannerInfoClass", " PDF \350\256\276\347\275\256", Q_NULLPTR));
        TL_PDF_EXPORT->setText(QApplication::translate("ExportScannerInfoClass", "\345\257\274\345\207\272      ", Q_NULLPTR));
        TL_PDF_EXPORT_ICON->setText(QString());
        TL_FTP->setText(QApplication::translate("ExportScannerInfoClass", " FTP \350\256\276\347\275\256", Q_NULLPTR));
        TL_FTP_SERVER->setText(QApplication::translate("ExportScannerInfoClass", "ftp \346\234\215\345\212\241\347\253\257  ", Q_NULLPTR));
        TL_FTP_SERVER_ICON->setText(QString());
        TL_FTP_CLIENT->setText(QApplication::translate("ExportScannerInfoClass", "ftp \345\256\242\346\210\267\347\253\257  ", Q_NULLPTR));
        TL_FTP_CLIENT_ICON->setText(QString());
        label_2->setText(QApplication::translate("ExportScannerInfoClass", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("ExportScannerInfoClass", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("ExportScannerInfoClass", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("ExportScannerInfoClass", "TextLabel", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ExportScannerInfoClass", "\350\277\220\350\241\214\350\256\276\347\275\256", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("ExportScannerInfoClass", "\347\250\213\345\272\217\345\220\257\345\212\250\350\207\252\345\212\250\345\274\200\345\220\257", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("ExportScannerInfoClass", "CheckBox", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ExportScannerInfoClass", "GroupBox", Q_NULLPTR));
        radioButton->setText(QApplication::translate("ExportScannerInfoClass", "RadioButton", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ExportScannerInfoClass", "\346\225\260\346\215\256\345\217\221\351\200\201", Q_NULLPTR));
        CHB_TCPS_ALL_CLIENT->setText(QApplication::translate("ExportScannerInfoClass", "\345\205\250\351\203\250", Q_NULLPTR));
        label_10->setText(QApplication::translate("ExportScannerInfoClass", " \345\256\242\346\210\267\347\253\257\357\274\232", Q_NULLPTR));
        LE_TCPS_CONTENT_CLIENT_PORT->setText(QApplication::translate("ExportScannerInfoClass", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        PB_TCPS_DISCONTENT_CLIENT->setText(QApplication::translate("ExportScannerInfoClass", "\346\226\255\345\274\200\350\277\236\346\216\245", Q_NULLPTR));
        label_6->setText(QApplication::translate("ExportScannerInfoClass", " \351\207\215\345\244\215\345\217\221\351\200\201\346\254\241\346\225\260\357\274\232", Q_NULLPTR));
        PB_TCPS_SEND->setText(QApplication::translate("ExportScannerInfoClass", " \345\217\221\351\200\201", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("ExportScannerInfoClass", "Socket \347\212\266\346\200\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("ExportScannerInfoClass", " \347\253\257\345\217\243\346\267\273\345\212\240\357\274\232", Q_NULLPTR));
        PB_TCPS_LISTEN_PORT_CREATE->setText(QApplication::translate("ExportScannerInfoClass", " \346\267\273\345\212\240", Q_NULLPTR));
        label_9->setText(QApplication::translate("ExportScannerInfoClass", "\345\275\223\345\211\215\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        TL_TCPS_LOCAL_PORT->setText(QApplication::translate("ExportScannerInfoClass", "null", Q_NULLPTR));
        label_8->setText(QApplication::translate("ExportScannerInfoClass", " \347\253\257\345\217\243\351\200\211\346\213\251\357\274\232", Q_NULLPTR));
        PB_TCPS_LISTENING->setText(QApplication::translate("ExportScannerInfoClass", " \345\220\257\345\212\250\347\233\221\345\220\254", Q_NULLPTR));
        PB_TCPS_LISTENED->setText(QApplication::translate("ExportScannerInfoClass", " \345\201\234\346\255\242\347\233\221\345\220\254", Q_NULLPTR));
        PB_TCPS_LISTEN_PORT_DELETE->setText(QApplication::translate("ExportScannerInfoClass", " \345\210\240\351\231\244", Q_NULLPTR));
        GB_TCP_SERVER_RECV->setTitle(QApplication::translate("ExportScannerInfoClass", "\346\225\260\346\215\256\346\216\245\346\224\266\345\217\212\346\217\220\347\244\272", Q_NULLPTR));
        label_13->setText(QApplication::translate("ExportScannerInfoClass", " \347\233\221\345\220\254\346\225\260\357\274\232", Q_NULLPTR));
        TL_TCPS_LISTEN_COUNT->setText(QApplication::translate("ExportScannerInfoClass", "0", Q_NULLPTR));
        label_11->setText(QApplication::translate("ExportScannerInfoClass", " \350\277\236\346\216\245\346\225\260\357\274\232", Q_NULLPTR));
        TL_TCPS_CLIENT_COUNT->setText(QApplication::translate("ExportScannerInfoClass", "0", Q_NULLPTR));
        PB_TCPS_START_RECV_CONTENT->setText(QApplication::translate("ExportScannerInfoClass", "\347\273\247\347\273\255\346\216\245\346\224\266", Q_NULLPTR));
        PB_TCPS_STOP_RECV_CONTENT->setText(QApplication::translate("ExportScannerInfoClass", "\345\205\263\351\227\255\346\216\245\346\224\266", Q_NULLPTR));
        PB_TCPS_RECV_CONTENT_CLEAR->setText(QApplication::translate("ExportScannerInfoClass", "\346\270\205\347\251\272", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("ExportScannerInfoClass", "\346\225\260\346\215\256\345\217\221\351\200\201", Q_NULLPTR));
        label_16->setText(QApplication::translate("ExportScannerInfoClass", " \351\207\215\345\244\215\345\217\221\351\200\201\346\254\241\346\225\260\357\274\232", Q_NULLPTR));
        PB_TCPC_SEND->setText(QApplication::translate("ExportScannerInfoClass", " \345\217\221\351\200\201", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("ExportScannerInfoClass", "Socket \347\212\266\346\200\201", Q_NULLPTR));
        label_17->setText(QApplication::translate("ExportScannerInfoClass", "   IP  \345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("ExportScannerInfoClass", "\345\275\223\345\211\215\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        LE_TCPC_LOCAL_PORT->setText(QApplication::translate("ExportScannerInfoClass", "null", Q_NULLPTR));
        label_19->setText(QApplication::translate("ExportScannerInfoClass", " \347\233\256\346\240\207\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        PB_TCPC_CONNECT->setText(QApplication::translate("ExportScannerInfoClass", " \350\277\236\346\216\245", Q_NULLPTR));
        PB_TCPC_DISCONNECT->setText(QApplication::translate("ExportScannerInfoClass", " \346\226\255\345\274\200", Q_NULLPTR));
        GB_TCP_SERVER_RECV_2->setTitle(QApplication::translate("ExportScannerInfoClass", "\346\225\260\346\215\256\346\216\245\346\224\266\345\217\212\346\217\220\347\244\272", Q_NULLPTR));
        PB_TCPC_START_RECV_CONTENT->setText(QApplication::translate("ExportScannerInfoClass", "\347\273\247\347\273\255\346\216\245\346\224\266", Q_NULLPTR));
        PB_TCPC_STOP_RECV_CONTENT->setText(QApplication::translate("ExportScannerInfoClass", "\345\205\263\351\227\255\346\216\245\346\224\266", Q_NULLPTR));
        PB_TCPC_RECV_CONTENT_CLEAR->setText(QApplication::translate("ExportScannerInfoClass", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExportScannerInfoClass: public Ui_ExportScannerInfoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTSCANNERINFO_H
