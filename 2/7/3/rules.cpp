#include "rules.h"

bool Rules::checkWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const
{
    bool win = false;
    for (int k = 0; k <= lengthToWin - 1 && !win; k++)
        win = checkDiagonalUpWin(field, i - k, j - k, size, lengthToWin);
    for (int k = 0; k <= lengthToWin - 1 && !win; k++)
        win = checkDiagonalDownWin(field, i + k, j - k, size, lengthToWin);
    for (int k = 0; k <= lengthToWin - 1 && !win; k++)
        win = checkHorizontalWin(field, i, j - k, size, lengthToWin);
    for (int k = 0; k <= lengthToWin - 1 && !win; k++)
        win = checkVerticalWin(field, i - k, j, size, lengthToWin);
    return win;
}

bool Rules::checkDiagonalUpWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const
{
    if (i < 1 || j < 1 || i + lengthToWin - 1 > size || j + lengthToWin - 1 > size)
        return false;
    bool win = true;
    for (int k = 1; k < lengthToWin && win; k++)
        if (field[i][j]->text() != field[i + k][j + k]->text())
            win = false;
    return win;
}

bool Rules::checkDiagonalDownWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const
{
    if (i < 1 || j < 1 || i > size || i - lengthToWin + 1 < 1 || j + lengthToWin - 1 > size)
        return false;
    bool win = true;
    for (int k = 1; k < lengthToWin && win; k++)
        if (field[i][j]->text() != field[i - k][j + k]->text())
            win = false;
    return win;
}

bool Rules::checkHorizontalWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const
{
    if (i < 1 || j < 1 || j + lengthToWin - 1 > size)
        return false;
    bool win = true;
    for (int k = 1; k < lengthToWin && win; k++)
        if (field[i][j]->text() != field[i][j + k]->text())
            win = false;
    return win;
}

bool Rules::checkVerticalWin(QPushButton ***field, int i, int j, int size, int lengthToWin) const
{
    if (i < 1 || j < 1 || i + lengthToWin - 1 > size)
        return false;
    bool win = true;
    for (int k = 1; k < lengthToWin && win; k++)
        if (field[i][j]->text() != field[i + k][j]->text())
            win = false;
    return win;
}
