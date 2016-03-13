#include "linkedlist.h"
#include "doublelinkedlist.h"

int main(int argc, char *argv[])
{
    List *linkedList = new LinkedList();
    for (int i = 0; i < 10; i++)
        linkedList->add(i);
    linkedList->print();
    linkedList->remove(10);
    linkedList->remove(0);
    linkedList->remove(9);
    if (linkedList->search(5) && !linkedList->search(10) && !linkedList->isEmpty() && !linkedList->remove(50))
        linkedList->print();
    delete linkedList;
    List *doubleLinkedList = new DoubleLinkedList();
    for (int i = 0; i < 10; i++)
        doubleLinkedList->add(i);
    doubleLinkedList->print();
    doubleLinkedList->remove(11);
    doubleLinkedList->remove(0);
    doubleLinkedList->remove(9);
    if (doubleLinkedList->search(5) && !doubleLinkedList->search(10) && !doubleLinkedList->isEmpty() && !doubleLinkedList->remove(50))
        doubleLinkedList->print();
    delete doubleLinkedList;
    return 0;
}
