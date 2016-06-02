/********************************************************************************
** Form generated from reading UI file 'bash.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASH_H
#define UI_BASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bash
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *next;
    QPushButton *rateUp;
    QPushButton *load;
    QLineEdit *rating;
    QPushButton *rateDown;
    QPushButton *bayan;
    QTextEdit *quote;
    QLabel *label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Bash)
    {
        if (Bash->objectName().isEmpty())
            Bash->setObjectName(QStringLiteral("Bash"));
        Bash->resize(300, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Bash->sizePolicy().hasHeightForWidth());
        Bash->setSizePolicy(sizePolicy);
        Bash->setMinimumSize(QSize(300, 250));
        Bash->setMaximumSize(QSize(300, 250));
        centralWidget = new QWidget(Bash);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setEnabled(false);

        gridLayout->addWidget(next, 2, 2, 1, 3);

        rateUp = new QPushButton(centralWidget);
        rateUp->setObjectName(QStringLiteral("rateUp"));
        rateUp->setEnabled(false);

        gridLayout->addWidget(rateUp, 1, 0, 1, 1);

        load = new QPushButton(centralWidget);
        load->setObjectName(QStringLiteral("load"));

        gridLayout->addWidget(load, 2, 0, 1, 2);

        rating = new QLineEdit(centralWidget);
        rating->setObjectName(QStringLiteral("rating"));
        rating->setEnabled(false);

        gridLayout->addWidget(rating, 1, 4, 1, 1);

        rateDown = new QPushButton(centralWidget);
        rateDown->setObjectName(QStringLiteral("rateDown"));
        rateDown->setEnabled(false);

        gridLayout->addWidget(rateDown, 1, 1, 1, 1);

        bayan = new QPushButton(centralWidget);
        bayan->setObjectName(QStringLiteral("bayan"));
        bayan->setEnabled(false);

        gridLayout->addWidget(bayan, 1, 2, 1, 1);

        quote = new QTextEdit(centralWidget);
        quote->setObjectName(QStringLiteral("quote"));
        quote->setEnabled(true);

        gridLayout->addWidget(quote, 4, 0, 1, 5);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 3, 1, 1);

        Bash->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Bash);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Bash->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Bash);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Bash->setStatusBar(statusBar);

        retranslateUi(Bash);

        QMetaObject::connectSlotsByName(Bash);
    } // setupUi

    void retranslateUi(QMainWindow *Bash)
    {
        Bash->setWindowTitle(QApplication::translate("Bash", "Bash", 0));
        next->setText(QApplication::translate("Bash", "Next", 0));
        rateUp->setText(QApplication::translate("Bash", "+", 0));
        load->setText(QApplication::translate("Bash", "Load", 0));
        rateDown->setText(QApplication::translate("Bash", "-", 0));
        bayan->setText(QApplication::translate("Bash", "[:::]", 0));
        quote->setHtml(QApplication::translate("Bash", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press Load</p></body></html>", 0));
        label->setText(QApplication::translate("Bash", "Rating", 0));
    } // retranslateUi

};

namespace Ui {
    class Bash: public Ui_Bash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASH_H
