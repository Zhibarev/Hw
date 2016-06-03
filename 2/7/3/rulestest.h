#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "rules.h"

class RulesTest : public QObject
{
   Q_OBJECT
public:
    explicit RulesTest(QObject *parent = 0) : QObject(parent) {}

private:
    Rules rules;
    int **field = nullptr;

private slots:

    void init()
    {

        field = new int*[4];
        for (int i = 1; i < 4; i++)
            field[i] = new int[4];
    }

    void cleanup()
    {
        for (int i = 1; i < 4; i++)
            delete []field[i];
        delete []field;
    }

    void testNoWin()
    {
        field[1][1] = 1;
        QVERIFY(!rules.checkWin(field, 1, 1, 3, 3));
        field[1][2] = -1;
        field[1][3] = 1;
        QVERIFY(!rules.checkWin(field, 1, 1, 3, 3));
    }

    void testHorizontalWin()
    {
        for (int i = 1; i < 4; i++)
            field[1][i] = 1;
        QVERIFY(rules.checkWin(field, 1, 1, 3, 3));
    }

    void testVerticalWin()
    {
        for (int i = 1; i < 4; i++)
            field[i][1] = 1;
        QVERIFY(rules.checkWin(field, 1, 1, 3, 3));
    }

    void testDiagonalUpWin()
    {
        for (int i = 1; i < 4; i++)
            field[i][i] = 1;
        QVERIFY(rules.checkWin(field, 1, 1, 3, 3));
    }

    void testDiagonalDownWin()
    {
        for (int i = 1; i < 4; i++)
            field[4 - i][i] = 1;
        QVERIFY(rules.checkWin(field, 3, 1, 3, 3));
    }
};
