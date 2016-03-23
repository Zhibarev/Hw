#include <iostream>
#include "linkedlist.h"

LinkedList::ListNode::ListNode(int newValue, ListNode *nextNode)
{
    next = nextNode;
    value = newValue;
}

LinkedList::~LinkedList()
{
    clear();
    delete head;
}

int LinkedList::length()
{
    return size;
}

void LinkedList::add(int newValue, int position)
{
    if (position <= (size + 1))
    {
        ListNode *runner = head;
        for (int i = 1; i < position; i++)
            runner = runner->next;
        runner->next = new ListNode(newValue, runner->next);
        size++;
    }
}

int LinkedList::remove(int position)
{
    if (position > size)
        return 0;
    ListNode *runner = head;
    for (int i = 1; i < position; i++)
        runner = runner->next;
    ListNode *newNext = runner->next->next;
    int removeValue = runner->next->value;
    delete runner->next;
    runner->next = newNext;
    size--;
    return removeValue;
}

int LinkedList::extract(int position)
{
    if (position > size)
        return 0;
    ListNode *runner = head;
    for (int i = 1; i <= position; i++)
        runner = runner->next;
    return runner->value;
}

bool LinkedList::empty()
{
    return head->next == nullptr;
}

int LinkedList::search(int value)
{
    ListNode *runner = head->next;
    int position = 1;
    while (runner != nullptr && runner->value != value)
    {
        runner = runner->next;
        position++;
    }
    if (runner == nullptr)
        return 0;
    return position;
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
    while (head->next != nullptr)
        remove(1);
}
