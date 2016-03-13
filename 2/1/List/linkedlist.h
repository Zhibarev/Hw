#pragma once
#include "list.h"

class LinkedList : public List
{
public:
    void add(int newValue);
    bool remove(int removedValue);
    void print();
    bool isEmpty();
    bool search(int searchedValue);
    void clear();
    ~LinkedList();
private:
    class ListNode
    {
    public:
        ListNode(int newValue);
        int value;
        ListNode *next = nullptr;
    };
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
};
