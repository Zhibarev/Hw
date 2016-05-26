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
       try
       {
           list->addUnique(1 ,1);
       }catch(const char* error)
       {
           QVERIFY(error == "Already include");
       }
   }

   void testAddOnWrongPosition()
   {
       try
       {
           list->addUnique(1 ,1);
       }catch(const char* error)
       {
           QVERIFY(error == "Already include");
       }
   }
};
