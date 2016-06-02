#pragma once

#include <QPushButton>

class Rules
{
public:
    bool checkWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const;

private:
    /**
   * @brief check is diagonal from i,j to (i + lengthToWin - 1, j + lengthToWin - 1) give win
   * @param i
   * @param j
   * @return if win return true, else return false
   */
    bool checkDiagonalDownWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const;
    /**
   * @brief check is diagonal from i,j to (i - lengthToWin + 1, j + lengthToWin - 1) give win
   * @param i
   * @param j
   * @return if win return true, else return false
   */
    bool checkDiagonalUpWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const;
    /**
   * @brief check is horizontal from i,j to (i + lengthToWin, j) give win
   * @param i
   * @param j
   * @return if win return true, else return false
   */
    bool checkHorizontalWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const;
    /**
   * @brief check is Vertical from i,j to (i, j + lengthToWin - 1) give win
   * @param i
   * @param j
   * @return if win return true, else return false
   */
    bool checkVerticalWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const;
};
