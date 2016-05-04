#pragma once

#include <QMainWindow>
#include <QSignalMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void append(const QString &symbol);
    void calculate();
    void clear();

private:
    Ui::MainWindow *ui;
    QSignalMapper *toAppend = new QSignalMapper(this);
};
