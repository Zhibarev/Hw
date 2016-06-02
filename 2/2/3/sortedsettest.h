#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QVector>
#include "sortedset.h"

class SortedSetTest : public QObject
{
   Q_OBJECT
public:
   explicit SortedSetTest(QObject *parent = 0) : QObject(parent) {}

private:
    SortedSet *set;

private slots:
    void init()
    {
        set = new SortedSet;
    }

    void cleanup()
    {
        delete set;
    }

    void testEmpty()
    {
        QVERIFY(set->empty());
    }

    void testAdd()
    {
        LinkedList *list = new LinkedList();
        set->add(list);
        QVERIFY(set->search(list) == 1);
        QVERIFY(set->extract(1) == list);
        delete list;
    }

    void testAddALot()
    {
        QVector<LinkedList> setOfLists(100);
        for (int i = 0; i < 100; i++)
        {
            setOfLists[i].add(i, 1);
            set->add(&setOfLists[i]);
        }
        for (int i = 0; i < 100; i++)
            QVERIFY(set->search(&setOfLists[i]));
    }

    void testRemove()
    {
        LinkedList *list = new LinkedList();
        set->add(list);
        set->remove(1);
        QVERIFY(set->search(list) == 0);
        delete list;
    }

    void testRemoveALot()
    {
        QVector<LinkedList> setOfLists(100);
        for (int i = 0; i < 100; i++)
        {
            setOfLists[i].add(i, 1);
            set->add(&setOfLists[i]);
        }
        for (int i = 0; i < 100; i++)
            QVERIFY(set->remove(1));
        for (int i = 0; i < 100; i++)
            QVERIFY(set->search(&setOfLists[i]) == 0);
    }

};
