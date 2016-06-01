#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void changeCell(int index);
    void createField();

private:
    Ui::MainWindow *ui;
    QSignalMapper *signalMapper = nullptr;
    const int size = 3;
    const int lengthToWin = 3;
    QPushButton *newGame = nullptr;
    QPushButton ***field = nullptr;
    bool isZero = false;

    void startNewGame();
    bool checkDiagonalDownWin(int i, int j) const;
    bool checkDiagonalUpWin(int i, int j) const;
    bool checkHorizontalWin(int i, int j) const;
    bool checkVerticalWin(int i, int j) const;
};
