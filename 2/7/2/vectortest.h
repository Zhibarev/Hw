#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void testIsZero()
    {
        Vector<int, 100> vector;
        QVERIFY(vector.isZero());
    }

    void testIndex()
    {
        Vector<int, 100> vector;
        for (int i = 0; i < 100; i++)
            vector[i] = i;
        for (int i = 0; i < 100; i++)
            QVERIFY(vector[i] == i);
    }

    void testOutOfRange()
    {
        Vector<int, 100> vector;
        QVERIFY_EXCEPTION_THROWN(vector[100], OutOfRange);
    }

    void testCopyConstructor()
    {
        Vector<int, 100> toCopy ;
        for (int i = 0; i < 100; i++)
            toCopy[i] = i;
        Vector<int, 100> vector(toCopy);
        for (int i = 0; i < 100; i++)
            QVERIFY(vector[i] == i);
    }

    void testSum()
    {
        Vector<int, 100> first;
        for (int i = 0; i < 100; i++)
            first[i] = i;
        Vector<int, 100> second(first);
        Vector<int, 100> sum = first + second;
        for (int i = 0; i < 100; i++)
            QVERIFY(sum[i] == 2*i);
    }

    void testSubstract()
    {
        Vector<int, 100> first;
        for (int i = 0; i < 100; i++)
            first[i] = 2*i;
        Vector<int, 100> second;
        for (int i = 0; i < 100; i++)
            second[i] = i;
        Vector<int, 100> substract = first - second;
        for (int i = 0; i < 100; i++)
            QVERIFY(substract[i] == i);
    }

    void testMultiply()
    {
        Vector<int, 10> first;
        for (int i = 0; i < 10; i++)
            first[i] = 2*i;
        Vector<int, 10> second;
        for (int i = 0; i < 10; i++)
            second[i] = i;
        int result = 0;
        for (int i = 1; i < 10; i++)
            result += i*i*2;
        QVERIFY(result == (first * second));
    }
};
