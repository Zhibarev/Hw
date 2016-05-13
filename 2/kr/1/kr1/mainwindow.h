#pragma once

#include <QMainWindow>
#include <QSignalMapper>
#include <QPushButton>

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
    void open(QPushButton *button);

private:
    void createField();
    Ui::MainWindow *ui;
    QSignalMapper *toOpen = new QSignalMapper(this);
    int getNumber(QPushButton *button);
    QPushButton *pressed = nullptr;
    int **field = nullptr;
    int size = 4;
    int buttonLength = 10;
};
