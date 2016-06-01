#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "uniquelist.h"

class UniqueListTest : public QObject
{
   Q_OBJECT
public:
   explicit UniqueListTest(QObject *parent = 0) : QObject(parent) {}

private:
    UniqueList *list = nullptr;

private slots:

   void init()
   {
       list = new UniqueList();
   }

   void cleanup()
   {
       delete list;
   }

   void testAddDublicate()
   {
       list->addUnique(1, 1);
       QVERIFY_EXCEPTION_THROWN(list->addUnique(1 , 1), AlreadyInclude);
   }

   void testAddOnWrongPosition()
   {
       QVERIFY_EXCEPTION_THROWN(list->addUnique(1, 10), OutOfRange);
   }

   void testRemoveFromWrongPosisition()
   {
       QVERIFY_EXCEPTION_THROWN(list->removeUnique(10), OutOfRange);
   }

   void testExtractFromWrongPosition()
   {
       QVERIFY_EXCEPTION_THROWN(list->extractUnique(1), OutOfRange);
   }
};
