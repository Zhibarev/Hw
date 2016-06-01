#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bag.h"

class BagTest : public QObject
{
   Q_OBJECT
public:
   explicit BagTest(QObject *parent = 0) : QObject(parent) {}

private:
    Bag<int> *bag;

private slots:

   void init()
   {
       bag = new Bag<int>();
   }

   void cleanup()
   {
       delete bag;
   }

   void testAdd()
   {
       bag->add(1);
       QVERIFY(bag->search(1));
   }

   void testRemoveNonexistentValue()
   {
       QVERIFY_EXCEPTION_THROWN(bag->remove(1), NothingToRemove);
   }

   void testAddDublicates()
   {
       bag->add(1);
       bag->add(1);
       bag->remove(1);
       bag->remove(1);
       QVERIFY_EXCEPTION_THROWN(bag->remove(1), NothingToRemove);
   }

   void testAddALot()
   {
       for (int i = 0; i < 1000; i++)
           bag->add(i);
       for (int i = 0; i < 1000; i++)
           QVERIFY(bag->search(i));
   }

   void testSize()
   {
       for (int i = 0; i < 1000; i++)
           bag->add(i);
       QVERIFY(bag->size() == 1000);
   }

   void testRemove()
   {
       bag->add(1);
       bag->remove(1);
       QVERIFY(!bag->search(1));
   }

   void testRemoveALot()
   {
       for (int i = 0; i < 1000; i++)
           bag->add(i);
       for (int i = 200; i < 300; i++)
           bag->remove(i);
       for (int i = 200; i < 300; i++)
           QVERIFY(!bag->search(i));
   }

   void testUnite()
   {
       for(int i = 0; i < 100; i++)
           bag->add(i);
       Bag<int> toUnite;
       for (int i = 60; i < 140; i++)
           toUnite.add(i);
       Bag<int> united = *bag + toUnite;
       for (int i = 0; i < 140; i++)
           QVERIFY(united.search(i));
       QVERIFY(united.size() == 180);
   }

   void testIntersection()
   {
       for(int i = 0; i < 100; i++)
           bag->add(i);
       Bag<int> toIntersection;
       for (int i = 60; i < 140; i++)
           toIntersection.add(i);
       Bag<int> intersection = *bag * toIntersection;
       for (int i = 60; i < 100; i++)
           QVERIFY(intersection.search(i));
       for (int i = 100; i < 140; i++)
           QVERIFY(!intersection.search(i));
   }
};
