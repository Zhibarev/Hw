/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QWidget *centralWidget;
    QPushButton *send;
    QPushButton *disconnect;
    QTextEdit *dialog;
    QPlainTextEdit *port;
    QLabel *label;
    QPlainTextEdit *toSend;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(270, 190);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Server->sizePolicy().hasHeightForWidth());
        Server->setSizePolicy(sizePolicy);
        Server->setMinimumSize(QSize(270, 190));
        Server->setMaximumSize(QSize(270, 190));
        centralWidget = new QWidget(Server);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        send = new QPushButton(centralWidget);
        send->setObjectName(QStringLiteral("send"));
        send->setEnabled(false);
        send->setGeometry(QRect(182, 94, 80, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(send->sizePolicy().hasHeightForWidth());
        send->setSizePolicy(sizePolicy1);
        send->setMinimumSize(QSize(80, 30));
        send->setMaximumSize(QSize(80, 30));
        disconnect = new QPushButton(centralWidget);
        disconnect->setObjectName(QStringLiteral("disconnect"));
        disconnect->setEnabled(false);
        disconnect->setGeometry(QRect(182, 63, 80, 23));
        sizePolicy1.setHeightForWidth(disconnect->sizePolicy().hasHeightForWidth());
        disconnect->setSizePolicy(sizePolicy1);
        disconnect->setMinimumSize(QSize(80, 0));
        disconnect->setMaximumSize(QSize(80, 16777215));
        dialog = new QTextEdit(centralWidget);
        dialog->setObjectName(QStringLiteral("dialog"));
        dialog->setGeometry(QRect(10, 0, 166, 90));
        dialog->setMinimumSize(QSize(130, 90));
        port = new QPlainTextEdit(centralWidget);
        port->setObjectName(QStringLiteral("port"));
        port->setEnabled(false);
        port->setGeometry(QRect(182, 32, 80, 25));
        port->setMinimumSize(QSize(80, 25));
        port->setMaximumSize(QSize(80, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(182, 0, 80, 26));
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(80, 16777215));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        toSend = new QPlainTextEdit(centralWidget);
        toSend->setObjectName(QStringLiteral("toSend"));
        toSend->setGeometry(QRect(10, 94, 166, 30));
        toSend->setMinimumSize(QSize(130, 30));
        toSend->setMaximumSize(QSize(16777215, 30));
        Server->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Server);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 270, 21));
        Server->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Server);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Server->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Server);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Server->setStatusBar(statusBar);

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QMainWindow *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", 0));
        send->setText(QApplication::translate("Server", "Send", 0));
        disconnect->setText(QApplication::translate("Server", "Disconnect", 0));
        dialog->setHtml(QApplication::translate("Server", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Connect...</p></body></html>", 0));
        label->setText(QApplication::translate("Server", "Port", 0));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
