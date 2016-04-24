/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSpinBox *firstNumber;
    QSpinBox *secondNumber;
    QLineEdit *result;
    QComboBox *action;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuSimpleCalc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(308, 109);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        firstNumber = new QSpinBox(centralWidget);
        firstNumber->setObjectName(QStringLiteral("firstNumber"));
        firstNumber->setGeometry(QRect(10, 10, 42, 41));
        secondNumber = new QSpinBox(centralWidget);
        secondNumber->setObjectName(QStringLiteral("secondNumber"));
        secondNumber->setGeometry(QRect(110, 10, 41, 41));
        result = new QLineEdit(centralWidget);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(180, 10, 113, 41));
        action = new QComboBox(centralWidget);
        action->setObjectName(QStringLiteral("action"));
        action->setGeometry(QRect(60, 10, 41, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 21, 21));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 308, 21));
        menuSimpleCalc = new QMenu(menuBar);
        menuSimpleCalc->setObjectName(QStringLiteral("menuSimpleCalc"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSimpleCalc->menuAction());
        menuSimpleCalc->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action->clear();
        action->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "+", 0)
         << QApplication::translate("MainWindow", "-", 0)
         << QApplication::translate("MainWindow", "*", 0)
         << QApplication::translate("MainWindow", "/", 0)
        );
        label->setText(QApplication::translate("MainWindow", "=", 0));
        menuSimpleCalc->setTitle(QApplication::translate("MainWindow", "SimpleCalc", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
