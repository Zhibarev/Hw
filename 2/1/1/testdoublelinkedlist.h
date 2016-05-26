#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "doublelinkedlist.h"

class DoubleLinkedListTest : public QObject
{
   Q_OBJECT
public:
   explicit DoubleLinkedListTest(QObject *parent = 0) : QObject(parent) {}

private:
    DoubleLinkedList *list = nullptr;

private slots:

   void init()
   {
       list = new DoubleLinkedList();
   }

   void cleanup()
   {
       delete list;
   }

   void testEmptyList()
   {
       QVERIFY(list->empty());
   }

   void testAdd()
   {
       for (int i = 0; i < 1000; i++)
           list->add(i, 1);
       for (int i = 0; i < 1000; i++)
           QVERIFY(list->search(i) == (1000 - i));
   }

   void testLength()
   {
       for (int i = 0; i < 1000; i++)
           list->add(i, 1);
       QVERIFY(list->length() == 1000);
   }

   void testExtract()
   {
       for (int i = 0; i < 1000; i++)
           list->add(i, 1);
       for (int i = 1; i <= 1000; i++)
           QVERIFY(list->extract(i) == (1000 - i));
   }

   void testClear()
   {
       for (int i = 0; i < 100; i++)
           list->add(0, 1);
       list->clear();
       QVERIFY(list->empty());
   }
};
