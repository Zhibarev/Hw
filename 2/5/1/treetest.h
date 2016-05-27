#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QString>
#include <string>
#include <fstream>
#include "tree.h"

class TreeTest : public QObject
{
   Q_OBJECT
public:
   explicit TreeTest(QObject *parent = 0) : QObject(parent) {}

private:
   Tree *tree;

private slots:
   void cleanup()
   {
       delete tree;
   }

   void testOneNumber()
   {
       tree = new Tree("1");
       QVERIFY(tree->calculate() == 1);
   }

   void testSimpleCalculate()
   {
       tree = new Tree("(+ 1 1)");
       QVERIFY(tree->calculate() == 2);
   }

   void testCalculate()
   {
       tree = new Tree("(+ (* (- 2 1) 5) (/ 2 1))");
       QVERIFY(tree->calculate() == 7);
   }

   void testPrint()
   {
       tree = new Tree("(+ 1 1)");
       std::ofstream out("out.txt");
       tree->print(out);
       out.close();
       std::ifstream in("out.txt");
       std::string expression = "";
       std::getline(in, expression);
       QVERIFY(expression == "(+ 1 1)");
   }
};
