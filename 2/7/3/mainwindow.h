#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>
#include "rules.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief Class to realize tictoctoe
 * Has to fields size(size of field) and lengthToWin(how many symbols in a row you need for win),
 * which install game's parameters
 */
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
    Rules rules;

    void startNewGame();
};
