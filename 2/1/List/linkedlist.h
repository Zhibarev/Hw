#pragma once
#include "list.h"

class LinkedList : public List
{
public:
    void add(int newValue, int position);
    int remove(int position);
    int extarct(int position);
    void print();
    bool empty();
    int length();
    int search(int value);
    void clear();
    ~LinkedList();
private:
    class ListNode
    {
    public:
        ListNode(int newValue, ListNode *nextNode);
        int value;
        ListNode *next;
    };
    ListNode *head = new ListNode(0, nullptr);
    int size = 0;
};
