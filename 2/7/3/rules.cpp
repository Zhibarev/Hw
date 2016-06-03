#include "rules.h"

bool Rules::checkWin(int **field, int i, int j, int size, int lengthToWin) const
{
    bool win = false;
    for (int k = 0; k <= lengthToWin - 1 && !win; k++)
        win = checkDiagonalUpWin(field, i - k, j - k, size, lengthToWin)
                || checkDiagonalDownWin(field, i + k, j - k, size, lengthToWin)
                    || checkHorizontalWin(field, i, j - k, size, lengthToWin)
                        || checkVerticalWin(field, i - k, j, size, lengthToWin);
    return win;
}

bool Rules::checkDiagonalUpWin(int **field, int i, int j, int size, int lengthToWin) const
{
    if (i < 1 || j < 1 || i + lengthToWin - 1 > size || j + lengthToWin - 1 > size)
        return false;
    bool win = true;
    for (int k = 1; k < lengthToWin && win; k++)
        if (field[i][j] != field[i + k][j + k])
            win = false;
    return win;
}

bool Rules::checkDiagonalDownWin(int **field, int i, int j, int size, int lengthToWin) const
{
    if (i < 1 || j < 1 || i > size || i - lengthToWin + 1 < 1 || j + lengthToWin - 1 > size)
        return false;
    bool win = true;
    for (int k = 1; k < lengthToWin && win; k++)
        if (field[i][j] != field[i - k][j + k])
            win = false;
    return win;
}

bool Rules::checkHorizontalWin(int **field, int i, int j, int size, int lengthToWin) const
{
    if (i < 1 || j < 1 || j + lengthToWin - 1 > size)
        return false;
    bool win = true;
    for (int k = 1; k < lengthToWin && win; k++)
        if (field[i][j] != field[i][j + k])
            win = false;
    return win;
}

bool Rules::checkVerticalWin(int **field, int i, int j, int size, int lengthToWin) const
{
    if (i < 1 || j < 1 || i + lengthToWin - 1 > size)
        return false;
    bool win = true;
    for (int k = 1; k < lengthToWin && win; k++)
        if (field[i][j] != field[i + k][j])
            win = false;
    return win;
}
