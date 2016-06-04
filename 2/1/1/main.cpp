#include <iostream>
#include "testlinkedlist.h"
#include "testdoublelinkedlist.h"

int main()
{
    LinkedListTest testLinkedList;
    QTest::qExec(&testLinkedList);
    DoubleLinkedListTest testDoubleLinkedList;
    QTest::qExec(&testDoubleLinkedList);
    return 0;
}
