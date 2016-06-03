#pragma once

class Rules
{
public:
    bool checkWin(int **field, int i, int j, int size, int lengthToWin) const;

private:
    /**
   * @brief check is diagonal from i,j to (i + lengthToWin - 1, j + lengthToWin - 1) give win
   * @param i
   * @param j
   * @return if win return true, else return false
   */
    bool checkDiagonalDownWin(int **field, int i, int j, int size, int lengthToWin) const;
    /**
   * @brief check is diagonal from i,j to (i - lengthToWin + 1, j + lengthToWin - 1) give win
   * @param i
   * @param j
   * @return if win return true, else return false
   */
    bool checkDiagonalUpWin(int **field, int i, int j, int size, int lengthToWin) const;
    /**
   * @brief check is horizontal from i,j to (i + lengthToWin, j) give win
   * @param i
   * @param j
   * @return if win return true, else return false
   */
    bool checkHorizontalWin(int **field, int i, int j, int size, int lengthToWin) const;
    /**
   * @brief check is Vertical from i,j to (i, j + lengthToWin - 1) give win
   * @param i
   * @param j
   * @return if win return true, else return false
   */
    bool checkVerticalWin(int **field, int i, int j, int size, int lengthToWin) const;
};
