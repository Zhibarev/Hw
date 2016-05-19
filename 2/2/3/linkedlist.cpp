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

int LinkedList::length() const
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

int LinkedList::extract(int position) const
{
    if (position > size)
        return 0;
    ListNode *runner = head;
    for (int i = 1; i <= position; i++)
        runner = runner->next;
    return runner->value;
}

bool LinkedList::empty() const
{
    return head->next == nullptr;
}

int LinkedList::search(int value) const
{
    ListNode *runner = head;
    int position = 0;
    do
    {
        runner = runner->next;
        position++;
    } while (runner != nullptr && runner->value != value);
    return position;
}

void LinkedList::print() const
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
