#include <iostream>
#include "linkedlist.h"

LinkedList::ListNode::ListNode(int newValue)
{
    value = newValue;
}

LinkedList::~LinkedList()
{
    clear();
    delete head;
}

void LinkedList::add(int newValue)
{
    tail->next = new ListNode(newValue);
    tail = tail->next;
}

bool LinkedList::remove(int removedValue)
{
    ListNode *runner = head;
    while (runner->next != nullptr && runner->next->value != removedValue)
        runner = runner->next;
    if (runner->next == nullptr)
        return false;
    ListNode *removedNode = runner->next;
    runner->next = removedNode->next;
    if (removedNode == tail)
        tail = runner;
    delete removedNode;
    return true;
}

bool LinkedList::isEmpty()
{
    return head->next == nullptr;
}

bool LinkedList::search(int searchedValue)
{
    ListNode *runner = head->next;
    while (runner != nullptr && runner->value != searchedValue)
        runner = runner->next;
    return runner != nullptr;
}

void LinkedList::print()
{
    ListNode *runner = head->next;
    while (runner != nullptr)
    {
        std::cout << runner->value << ' ';
        runner = runner->next;
    }
    std ::cout << '\n';
}

void LinkedList::clear()
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
