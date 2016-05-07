/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *expression;
    QGridLayout *gridLayout;
    QPushButton *minus;
    QPushButton *divide;
    QPushButton *multiply;
    QPushButton *button9;
    QPushButton *point;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *plus;
    QPushButton *button6;
    QPushButton *button0;
    QPushButton *button1;
    QPushButton *button3;
    QPushButton *button2;
    QPushButton *equality;
    QPushButton *pushButton;
    QPushButton *clear;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(425, 402);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        expression = new QLineEdit(centralWidget);
        expression->setObjectName(QStringLiteral("expression"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(expression->sizePolicy().hasHeightForWidth());
        expression->setSizePolicy(sizePolicy);
        expression->setMinimumSize(QSize(0, 35));
        expression->setMaximumSize(QSize(16777215, 16776767));
        QFont font;
        font.setFamily(QStringLiteral("Script MT Bold"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        expression->setFont(font);

        verticalLayout->addWidget(expression);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        minus = new QPushButton(centralWidget);
        minus->setObjectName(QStringLiteral("minus"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(minus->sizePolicy().hasHeightForWidth());
        minus->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("Script MT Bold"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        minus->setFont(font1);

        gridLayout->addWidget(minus, 0, 3, 1, 3);

        divide = new QPushButton(centralWidget);
        divide->setObjectName(QStringLiteral("divide"));
        sizePolicy1.setHeightForWidth(divide->sizePolicy().hasHeightForWidth());
        divide->setSizePolicy(sizePolicy1);
        divide->setFont(font1);

        gridLayout->addWidget(divide, 0, 2, 1, 1);

        multiply = new QPushButton(centralWidget);
        multiply->setObjectName(QStringLiteral("multiply"));
        sizePolicy1.setHeightForWidth(multiply->sizePolicy().hasHeightForWidth());
        multiply->setSizePolicy(sizePolicy1);
        multiply->setFont(font1);

        gridLayout->addWidget(multiply, 2, 3, 1, 3);

        button9 = new QPushButton(centralWidget);
        button9->setObjectName(QStringLiteral("button9"));
        sizePolicy1.setHeightForWidth(button9->sizePolicy().hasHeightForWidth());
        button9->setSizePolicy(sizePolicy1);
        button9->setFont(font1);

        gridLayout->addWidget(button9, 5, 2, 1, 1);

        point = new QPushButton(centralWidget);
        point->setObjectName(QStringLiteral("point"));
        sizePolicy1.setHeightForWidth(point->sizePolicy().hasHeightForWidth());
        point->setSizePolicy(sizePolicy1);
        point->setFont(font1);

        gridLayout->addWidget(point, 6, 2, 1, 1);

        button4 = new QPushButton(centralWidget);
        button4->setObjectName(QStringLiteral("button4"));
        sizePolicy1.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy1);
        button4->setFont(font1);

        gridLayout->addWidget(button4, 4, 0, 1, 1);

        button5 = new QPushButton(centralWidget);
        button5->setObjectName(QStringLiteral("button5"));
        sizePolicy1.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QStringLiteral("Script MT Bold"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        button5->setFont(font2);

        gridLayout->addWidget(button5, 4, 1, 1, 1);

        button7 = new QPushButton(centralWidget);
        button7->setObjectName(QStringLiteral("button7"));
        sizePolicy1.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy1);
        button7->setFont(font1);

        gridLayout->addWidget(button7, 5, 0, 1, 1);

        button8 = new QPushButton(centralWidget);
        button8->setObjectName(QStringLiteral("button8"));
        sizePolicy1.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy1);
        button8->setFont(font1);

        gridLayout->addWidget(button8, 5, 1, 1, 1);

        plus = new QPushButton(centralWidget);
        plus->setObjectName(QStringLiteral("plus"));
        sizePolicy1.setHeightForWidth(plus->sizePolicy().hasHeightForWidth());
        plus->setSizePolicy(sizePolicy1);
        plus->setFont(font1);

        gridLayout->addWidget(plus, 4, 3, 1, 3);

        button6 = new QPushButton(centralWidget);
        button6->setObjectName(QStringLiteral("button6"));
        sizePolicy1.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy1);
        button6->setFont(font1);

        gridLayout->addWidget(button6, 4, 2, 1, 1);

        button0 = new QPushButton(centralWidget);
        button0->setObjectName(QStringLiteral("button0"));
        sizePolicy1.setHeightForWidth(button0->sizePolicy().hasHeightForWidth());
        button0->setSizePolicy(sizePolicy1);
        button0->setFont(font1);

        gridLayout->addWidget(button0, 6, 0, 1, 2);

        button1 = new QPushButton(centralWidget);
        button1->setObjectName(QStringLiteral("button1"));
        sizePolicy1.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy1);
        button1->setFont(font1);

        gridLayout->addWidget(button1, 2, 0, 1, 1);

        button3 = new QPushButton(centralWidget);
        button3->setObjectName(QStringLiteral("button3"));
        sizePolicy1.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QStringLiteral("Script MT Bold"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        button3->setFont(font3);

        gridLayout->addWidget(button3, 2, 2, 1, 1);

        button2 = new QPushButton(centralWidget);
        button2->setObjectName(QStringLiteral("button2"));
        sizePolicy1.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy1);
        button2->setFont(font1);

        gridLayout->addWidget(button2, 2, 1, 1, 1);

        equality = new QPushButton(centralWidget);
        equality->setObjectName(QStringLiteral("equality"));
        sizePolicy1.setHeightForWidth(equality->sizePolicy().hasHeightForWidth());
        equality->setSizePolicy(sizePolicy1);
        equality->setFont(font1);

        gridLayout->addWidget(equality, 5, 5, 2, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setPointSize(16);
        pushButton->setFont(font4);

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        sizePolicy1.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy1);
        clear->setFont(font1);

        gridLayout->addWidget(clear, 5, 4, 2, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setFont(font4);

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 425, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        expression->setText(QString());
        minus->setText(QApplication::translate("MainWindow", "-", 0));
        divide->setText(QApplication::translate("MainWindow", "/", 0));
        multiply->setText(QApplication::translate("MainWindow", "*", 0));
        button9->setText(QApplication::translate("MainWindow", "9", 0));
        point->setText(QApplication::translate("MainWindow", ".", 0));
        button4->setText(QApplication::translate("MainWindow", "4", 0));
        button5->setText(QApplication::translate("MainWindow", "5", 0));
        button7->setText(QApplication::translate("MainWindow", "7", 0));
        button8->setText(QApplication::translate("MainWindow", "8", 0));
        plus->setText(QApplication::translate("MainWindow", "+", 0));
        button6->setText(QApplication::translate("MainWindow", "6", 0));
        button0->setText(QApplication::translate("MainWindow", "0", 0));
        button1->setText(QApplication::translate("MainWindow", "1", 0));
        button3->setText(QApplication::translate("MainWindow", "3", 0));
        button2->setText(QApplication::translate("MainWindow", "2", 0));
        equality->setText(QApplication::translate("MainWindow", "=", 0));
        pushButton->setText(QApplication::translate("MainWindow", ")", 0));
        clear->setText(QApplication::translate("MainWindow", "C", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "(", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
