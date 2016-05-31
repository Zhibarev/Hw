#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sharedpointer.h"

class PointerTest : public QObject
{
   Q_OBJECT
public:
   explicit PointerTest(QObject *parent = 0) : QObject(parent) {}

private slots:

   void testGet()
   {
       int *cell = new int(1);
       SharedPointer<int> pointer(cell);
       QVERIFY(pointer.get() == cell);
   }

   void testReturn()
   {
       SharedPointer<int> pointer(new int(1));
       QVERIFY(*pointer == 1);
   }

   void testCopy()
   {
       SharedPointer<int> pointer(new int(1));
       SharedPointer<int> newPointer(new int(2));
       newPointer = pointer;
       QVERIFY(*pointer == *newPointer);
       QVERIFY(pointer.get() == newPointer.get());
       QVERIFY(pointer.count() == 2);
   }

   void testRemove()
   {
       SharedPointer<int> pointer(new int(1));
       SharedPointer<int> newPointer = pointer;
       newPointer.~SharedPointer();
       QVERIFY(pointer.count() == 1);
   }
};
