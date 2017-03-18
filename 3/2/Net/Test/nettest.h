#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "Net/localnet.h"
#include "Computer/weakos.h"
#include "Computer/windows.h"
#include "Computer/linux.h"

class NetTest : public QObject
{
   Q_OBJECT
public:
   explicit NetTest(QObject *parent = 0) : QObject(parent) {}

private:
    QVector<Computer*> computers;
    QVector<QVector<bool>> links;
    LocalNet *localNet = nullptr;

private slots:

   void cleanup()
   {
       delete localNet;
       links.clear();
       computers.clear();
   }

   void testAttackAllSystems()
   {
       int size = 3;
       computers.push_back(new Computer(new Windows, true));
       computers.push_back(new Computer(new Windows, false));
       computers.push_back(new Computer(new Linux, false));
       links.resize(size);
       for (int i = 0; i < size; i++)
       {
           links[i].resize(size);
           for (int j = 0; j < size; j++)
               links[i][j] = true;
       }
       localNet = new LocalNet(computers, links);
       for (int i = 0; i < 1000; i++)
                  localNet->step();
       for (int i = 1; i < size; i++)
           QVERIFY(computers[i]->isInfected());
   }

   void testUnlinkedNet()
   {
       computers.push_back(new Computer(new Windows, true));
       int size = 10;
       for (int i = 0; i < size - 1; i++)
            computers.push_back(new Computer(new WeakOS, false));
       links.resize(size);
       for (int i = 0; i < size; i++)
           links[i].resize(size);
       localNet = new LocalNet(computers, links);
       for (int i = 0; i < 100; i++)
           localNet->step();
       for (int i = 1; i < size; i++)
           QVERIFY(!computers[i]->isInfected());
   }

   void testLinkedComps()
   {
       computers.push_back(new Computer(new Windows, true));
       int size = 10;
       for (int i = 0; i < size - 1; i++)
            computers.push_back(new Computer(new WeakOS, false));
       links.resize(size);
       for (int i = 0; i < size; i++)
       {
           links[i].resize(size);
           links[i][(i + 1) % size] = true;
           links[i][(i - 1 + size) % size] = true;
       }
       localNet = new LocalNet(computers, links);
       for (int i = 1; i <= 3; i++)
       {
           localNet->step();
           QVERIFY(computers[i]->isInfected() && computers[size - i]->isInfected() && localNet->getCountOfInfected() == i * 2 + 1);
       }
   }
};
