#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>

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

    void startNewGame();
    /**
     * @brief check is diagonal from i,j to (i + lengthToWin - 1, j + lengthToWin - 1) give win
     * @param i
     * @param j
     * @return if win return true, else return false
     */
    bool checkDiagonalDownWin(int i, int j) const;
    /**
     * @brief check is diagonal from i,j to (i - lengthToWin + 1, j + lengthToWin - 1) give win
     * @param i
     * @param j
     * @return if win return true, else return false
     */
    bool checkDiagonalUpWin(int i, int j) const;
    /**
     * @brief check is horizontal from i,j to (i + lengthToWin, j) give win
     * @param i
     * @param j
     * @return if win return true, else return false
     */
    bool checkHorizontalWin(int i, int j) const;
    /**
     * @brief check is Vertical from i,j to (i, j + lengthToWin - 1) give win
     * @param i
     * @param j
     * @return if win return true, else return false
     */
    bool checkVerticalWin(int i, int j) const;
};
