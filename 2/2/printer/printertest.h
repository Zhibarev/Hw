#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "fileprinter.h"
#include <cstdio>
#include <iostream>

class PrinterTest : public QObject
{
   Q_OBJECT
public:
   explicit PrinterTest(QObject *parent = 0) : QObject(parent) {}

private:
    FilePrinter *printer = nullptr;
    FILE *out = nullptr;

private slots:
   void init()
   {
       out = fopen("./test.txt", "w");
       printer = new FilePrinter(out);
   }

   void cleanup()
   {
       delete printer;
   }

   void testOneElement()
   {
       int **array = new int*[1];
       array[0] = new int[1];
       array[0][0] = 1;
       printer->print(array, 1);
       fclose(out);
       FILE *in = fopen("./test.txt", "r");
       int value = 0;
       fscanf(in, "%d", &value);
       fclose(in);
       QVERIFY(value == 1);
       delete []array[0];
       delete []array;
   }

   void testALot()
   {
       int **array = new int*[5];
       for (int i = 0; i < 5; i++)
           array[i] = new int[5];
       for (int i = 0; i < 25; i++)
           array[i / 5][i % 5] = i;
       printer->print(array, 5);
       fclose(out);
       FILE *in = fopen("./test.txt", "r");
       int result[25] = {0, 1, 2, 3, 4, 9, 14, 19, 24, 23, 22, 21, 20, 15, 10, 5, 6, 7, 8, 13, 18, 17, 16, 11, 12};
       for (int i = 0; i < 25; i++)
       {
           int value = 0;
           fscanf(in, "%d", &value);
           QVERIFY(value == result[i]);
       }
       fclose(in);
       for (int i = 0; i < 5; i++)
           delete []array[i];
       delete []array;
   }

};
