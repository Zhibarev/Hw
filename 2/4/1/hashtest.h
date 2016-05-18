#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QString>
#include <string>
#include "hashtable.h"
#include "hashsimple.h"

class HashTest : public QObject
{
   Q_OBJECT
public:
   explicit HashTest(QObject *parent = 0) : QObject(parent) {}

private:
   HashSimple *hash;
   HashTable *table;

private slots:
   void init()
   {
       hash = new HashSimple();
       table = new HashTable(hash, 10);
   }

   void cleanup()
   {
       delete table;

   }

   void testAdd()
   {
       table->add("1");
       QVERIFY(table->search("1"));
   }

   void testAddALot()
   {
       for (int i = 0; i < 1000; i++)
       {
           table->add(QString::number(i).toStdString());
       }
       QVERIFY(table->countOfElements() == 1000);
   }

   void testRemove()
   {
        table->add("1");
        table->remove("1");
        QVERIFY(!table->search("1"));
   }

   void testLengthOfMaxColumm()
   {
       for (int i = 0; i < 100; i++)
           table->add("1");
       for (int i = 0; i < 101; i++)
           table->add("2");
       long int length = table->lengthOfMaxColumn();
       QVERIFY(table->lengthOfMaxColumn() == 101);
   }

   void testLoadFactor()
   {
       for (int i = 0; i < 100; i++)
           table->add("1");
       for (int i = 0; i < 201; i++)
           table->add("2");
       QVERIFY(table->loadFactor() - (double) table->countOfElements() / (double) table->countOfColumns() < 0.00000001 && table->loadFactor() - (double) table->countOfElements() / (double) table->countOfColumns() > -0.00000001);
   }

   void testCountOfEmptyColums()
   {
       table->add("1");
       table->add("2");
       table->add("3");
       QVERIFY(table->countOfEmptyColumns() == (table->countOfColumns() - 3));
   }
};

