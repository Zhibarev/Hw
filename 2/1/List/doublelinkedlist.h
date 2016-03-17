#pragma once
#include "list.h"

class DoubleLinkedList : public List
{
public:
    DoubleLinkedList();
    void add(int newValue, int position);
    int remove(int position);
    int extract(int position);
    void print();
    bool empty();
    int length();
    int search(int value);
    void clear();
    ~DoubleLinkedList();
private:
    class ListNode
    {
    public:
        ListNode(int newValue, ListNode *previusNode, ListNode *nextNode);
        int value;
        ListNode *next;
        ListNode *previous;
    };
    ListNode *head;
    ListNode *tail;
    int size = 0;
};
