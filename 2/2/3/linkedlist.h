#pragma once
#include "list.h"

class LinkedList : public List
{
public:
    void add(int newValue);
    bool remove(int removedValue);
    void print();
    bool empty();
    bool search(int searchedValue);
    void clear();
    int size();
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
    int size = 0;
};
