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
    QPushButton ***field = nullptr;

private slots:

    void init()
    {

        field = new QPushButton**[4];
        for (int i = 1; i < 4; i++)
            field[i] = new QPushButton*[4];
        for (int i = 1; i < 4; i++)
            for (int j = 1; j < 4; j++)
                field[i][j] = new QPushButton;
    }

    void cleanup()
    {
        for (int i = 1; i < 4; i++)
            for (int j = 1; j < 4; j++)
                delete field[i][j];
        for (int i = 1; i < 4; i++)
            delete []field[i];
        delete []field;
    }

    void testNoWin()
    {
        field[1][1]->setText("X");
        QVERIFY(!rules.checkWin(field, 1, 1, 3, 3));
        field[1][2]->setText("O");
        field[1][3]->setText("X");
        QVERIFY(!rules.checkWin(field, 1, 1, 3, 3));
    }

    void testHorizontalWin()
    {
        for (int i = 1; i < 4; i++)
            field[1][i]->setText("X");
        QVERIFY(rules.checkWin(field, 1, 1, 3, 3));
    }

    void testVerticalWin()
    {
        for (int i = 1; i < 4; i++)
            field[i][1]->setText("X");
        QVERIFY(rules.checkWin(field, 1, 1, 3, 3));
    }

    void testDiagonalUpWin()
    {
        for (int i = 1; i < 4; i++)
            field[i][i]->setText("X");
        QVERIFY(rules.checkWin(field, 1, 1, 3, 3));
    }

    void testDiagonalDownWin()
    {
        for (int i = 1; i < 4; i++)
            field[4 - i][i]->setText("X");
        QVERIFY(rules.checkWin(field, 3, 1, 3, 3));
    }
};
