#pragma once
#include "list.h"

///@brief int Linked List
class LinkedList : public List
{
public:
    void add(int newValue, int position);
    int remove(int position);
    int extract(int position) const;
    void print() const;
    bool empty() const;
    int length() const;
    int search(int value) const;
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
