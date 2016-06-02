#include "mainwindow.h"
#include <QApplication>
#include "rulestest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RulesTest test;
    QTest::qExec(&test);

    MainWindow w;
    w.show();

    return a.exec();
}
