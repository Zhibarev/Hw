#include <iostream>
#include "doublelinkedlist.h"

DoubleLinkedList::ListNode::ListNode(int newValue, ListNode *previusNode, ListNode *nextNode)
{
    value = newValue;
    previus = previusNode;
    next = nextNode;
}

DoubleLinkedList::~DoubleLinkedList()
{
    clear();
    delete head;
}


void DoubleLinkedList::add(int newValue)
{
    tail->next = new ListNode(newValue, tail, nullptr);
    tail = tail->next;
}

bool DoubleLinkedList::remove(int removedValue)
{
    ListNode *runner = head->next;
    while (runner != nullptr && runner->value != removedValue)
        runner = runner->next;
    if (runner == nullptr)
        return false;
    runner->previus->next = runner->next;
    if (runner == tail)
        tail = tail->previus;
    delete runner;
    return true;
}

bool DoubleLinkedList::isEmpty()
{
    return head->next == nullptr;
}

bool DoubleLinkedList::search(int searchedValue)
{
    ListNode *runner = head->next;
    while (runner != nullptr && runner->value != searchedValue)
        runner = runner->next;
    return runner != nullptr;
}

void DoubleLinkedList::print()
{
    ListNode *runner = head->next;
    while (runner != nullptr)
    {
        std::cout << runner->value << ' ';
        runner = runner->next;
    }
    std::cout << '\n';
}

void DoubleLinkedList::clear()
{
    ListNode *removedNode = head->next;
    while (removedNode != nullptr)
    {
        head->next = head->next->next;
        delete removedNode;
        removedNode = head->next;
    }
    tail = head;
}
