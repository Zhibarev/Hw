#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "Computer/computer.h"
#include "Computer/windows.h"
#include "Computer/weakos.h"

class ComputerTest : public QObject
{
   Q_OBJECT
public:
   explicit ComputerTest(QObject *parent = 0) : QObject(parent) {}

private:
    Computer *computer = nullptr;

private slots:

   void cleanup()
   {
       delete computer;
   }

   void testWeakOS()
   {
       computer = new Computer(new WeakOS, false);
       QVERIFY(computer->attack());
   }

   void testWindows()
   {
       computer = new Computer(new Windows, false);
       int infectCount = 0;
       for (int j = 0; j < 1000; j++)
       {
           if (computer->attack())
           {
                infectCount++;
                computer->changeInfection(false);
           }
       }
       float percent = float(1000) / (float)infectCount;
       QVERIFY (percent - 5 < 0.5 && 5 - percent < 0.5);
   }
};
