#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linkedstack.h"

class LinkedStackTest : public QObject
{
   Q_OBJECT
public:
   explicit LinkedStackTest(QObject *parent = 0) : QObject(parent) {}

private:
    LinkedStack *stack = nullptr;

private slots:

   void init()
   {
       stack = new LinkedStack();
   }

   void cleanup()
   {
       delete stack;
   }

   void testEmpty()
   {
       QVERIFY(stack->isEmpty());
   }

   void testPushPop()
   {
       for (int i = 0; i < 1000; i++)
           stack->push(i);
       for (int i = 1; i <= 1000; i++)
           QVERIFY(stack->pop() == (1000 - i));
   }

   void testLength()
   {
       for (int i = 0; i < 1000; i++)
           stack->push(i);
       QVERIFY(stack->length() == 1000);
   }

   void testTop()
   {
       for (int i = 0; i < 2; i++)
           stack->push(i);
       QVERIFY(stack->top() == 1);
   }
};
