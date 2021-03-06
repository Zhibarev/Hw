#pragma once
#include "list.h"

/**
 * @brief Realize of linked list with two guardian - pointer on first elements of list
 */
class LinkedList : public List
{
public:
    void add(int newValue, int position);
    int remove(int position);
    int extract(int position);
    void print();
    bool empty();
    int length();
    int search(int value);
    void clear();

    ~LinkedList();
private:
    /**
     * @brief Node of linked list
     */
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
