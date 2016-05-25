#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"

class SetTest : public QObject
{
   Q_OBJECT
public:
   explicit SetTest(QObject *parent = 0) : QObject(parent) {}

private:
    Set<int> *set;

private slots:

   void init()
   {
       set = new Set<int>();
   }

   void cleanup()
   {
       delete set;
   }

   void testAdd()
   {
       set->add(1);
       QVERIFY(set->search(1));
   }

   void testAddALot()
   {
       for (int i = 0; i < 1000; i++)
           set->add(i);
       for (int i = 0; i < 1000; i++)
           QVERIFY(set->search(i));
   }

   void testRemove()
   {
       set->remove(1);
       set->add(1);
       set->remove(1);
       QVERIFY(!set->search(1));
   }

   void testRemoveALot()
   {
       for (int i = 0; i < 1000; i++)
           set->add(i);
       for (int i = 200; i < 300; i++)
           set->remove(i);
       for (int i = 200; i < 300; i++)
           QVERIFY(!set->search(i));
   }

   void testUnite()
   {
       for(int i = 0; i < 100; i++)
           set->add(i);
       Set<int> toUnite;
       for (int i = 60; i < 140; i++)
           toUnite.add(i);
       Set<int> united = *set + toUnite;
       for (int i = 0; i < 140; i++)
           QVERIFY(united.search(i));
        toUnite.clear();
        united.clear();
   }

   void testIntersection()
   {
       for(int i = 0; i < 100; i++)
           set->add(i);
       Set<int> toIntersection;
       for (int i = 60; i < 140; i++)
           toIntersection.add(i);
       Set<int> intersection = *set * toIntersection;
       for (int i = 60; i < 100; i++)
           QVERIFY(intersection.search(i));
       for (int i = 100; i < 140; i++)
           QVERIFY(!intersection.search(i));
   }
};
