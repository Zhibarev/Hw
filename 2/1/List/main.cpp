#include "linkedlist.h"
#include "doublelinkedlist.h"

int main()
{
    List *linkedList = new LinkedList();
    for (int i = 0; i < 10; i++)
        linkedList->add(i, i + 1);
    linkedList->print();
    linkedList->remove(1);
    linkedList->remove(2);
    if (linkedList->search(1) == 1 && !linkedList->empty())
        linkedList->print();
    delete linkedList;
    List *doubleLinkedList = new DoubleLinkedList();
    for (int i = 0; i < 10; i++)
        doubleLinkedList->add(i, i + 1);
    doubleLinkedList->print();
    doubleLinkedList->remove(1);
    doubleLinkedList->remove(2);
    if (doubleLinkedList->search(1) == 1 && !doubleLinkedList->empty())
        doubleLinkedList->print();
    delete doubleLinkedList;
    return 0;
}
