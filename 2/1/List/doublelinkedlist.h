#pragma once
#include "list.h"

class DoubleLinkedList : public List
{
public:
    void add(int newValue);
    bool remove(int removedValue);
    void print();
    bool isEmpty();
    bool search(int searchedValue);
    void clear();
    ~DoubleLinkedList();
private:
    class ListNode
    {
    public:
        ListNode(int newValue, ListNode *previusNode, ListNode *nextNode);
        int value;
        ListNode *next;
        ListNode *previus;
    };
    ListNode *head = new ListNode(0, nullptr, nullptr);
    ListNode *tail = head;
};
