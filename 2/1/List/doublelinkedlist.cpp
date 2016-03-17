#include <iostream>
#include "doublelinkedlist.h"

DoubleLinkedList::ListNode::ListNode(int newValue, ListNode *previousNode, ListNode *nextNode)
{
    next = nextNode;
    previous = previousNode;
    value = newValue;
}

DoubleLinkedList::DoubleLinkedList()
{
    head = new ListNode(0, nullptr, nullptr);
    tail = new ListNode(0, head, nullptr);
    head->next = tail;
}

DoubleLinkedList::~DoubleLinkedList()
{
    clear();
    delete head;
    delete tail;
}

int DoubleLinkedList::length()
{
    return size;
}

void DoubleLinkedList::add(int newValue, int position)
{
    if (position <= (size + 1))
    {
        ListNode *runner = head;
        for (int i = 1; i < position; i++)
            runner = runner->next;
        runner->next = new ListNode(newValue, runner, runner->next);
        runner->next->next->previous = runner->next;
        size++;
    }
}

int DoubleLinkedList::remove(int position)
{
    if (position > size)
        return 0;
    ListNode *runner = head;
    for (int i = 1; i <= position; i++)
        runner = runner->next;
    runner->previous->next = runner->next;
    runner->next->previous = runner->previous;
    int removeValue = runner->value;
    delete runner;
    size--;
    return removeValue;
}

int DoubleLinkedList::extarct(int position)
{
    if (position > size)
        return 0;
    ListNode *runner = head;
    for (int i = 1; i <= position; i++)
        runner = runner->next;
    return runner->value;
}

bool DoubleLinkedList::empty()
{
    return head->next == tail;
}

int DoubleLinkedList::search(int value)
{
    ListNode *runner = head;
    int position = 0;
    do
    {
        runner = runner->next;
        position++;
    } while (runner != tail && runner->value != value);
    return position;
}

void DoubleLinkedList::print()
{
    ListNode *runner = head->next;
    while (runner != tail)
    {
        std::cout << runner->value << ' ';
        runner = runner->next;
    }
    std ::cout << '\n';
}

void DoubleLinkedList::clear()
{
    while (head->next != tail)
        remove(1);
}
