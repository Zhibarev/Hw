#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QString>
#include <string>
#include "hashfunction.h"
#include "hashfaq6.h"
#include "hashrot13.h"
#include "hashsimple.h"

class HashFunctionTest : public QObject
{
   Q_OBJECT
public:
   explicit HashFunctionTest(QObject *parent = 0) : QObject(parent) {}

private:
   HashFunction *hash;
   std::string str = "test";
   int key = 97;

private slots:

   void cleanup()
   {
       delete hash;
   }

   void testSimple()
   {
       hash = new HashSimple();
       QVERIFY(hash->hash(str, key) == 60);
   }

   void testROT13()
   {
       hash = new HashROT13();
       QVERIFY(hash->hash(str, key) == 66);
   }

   void testFAQ6()
   {
       hash = new HashFAQ6();
       QVERIFY(hash->hash(str, key) == 30);
   }
};

