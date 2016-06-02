#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "quicksort.h"
#include "bubblesort.h"
#include "heapsort.h"
#include "insertsort.h"
#include "selectionsort.h"
#include "quicksort.h"
#include <algorithm>
#include <ctime>
#include <random>

class SortTest : public QObject
{
   Q_OBJECT
public:
   explicit SortTest(QObject *parent = 0) : QObject(parent) {}

private:
    Sort *sort;

    void testSort(int size)
    {
        srand(time(0));
        int *array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = rand();
        sort->sort(array, 0, size - 1);
        for (int i = 0; i < size - 1; i++)
            QVERIFY(array[i] <= array[i + 1]);
    }

private slots:

    void cleanup()
    {
        delete sort;
    }

    void testQuickSort()
    {
        sort = new QuickSort;
        testSort(100);
    }

    void testHeapSort()
    {
        sort = new HeapSort;
        testSort(100);
    }

    void testBubbleSort()
    {
        sort = new BubbleSort;
        testSort(100);
    }

    void testInsertSort()
    {
        sort = new InsertSort;
        testSort(100);
    }

    void testSelectionSort()
    {
        sort = new SelectionSort;
        testSort(100);
    }
};
