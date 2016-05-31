#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "stackcalculator.h"

class CalculatorTest : public QObject
{
   Q_OBJECT
public:
   explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

private:
    StackCalculator calculator;

private slots:

    void testSimpleCalculate()
    {
        QVERIFY(calculator.calculator("1+1") == 2);
    }

    void testCalculate()
    {
        QVERIFY(calculator.calculator("1+(6*3)/2-5") == 5);
    }
};
