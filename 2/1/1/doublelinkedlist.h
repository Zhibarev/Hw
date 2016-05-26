#pragma once
#include "list.h"

/**
 * @brief Realize of doublelinked list with two guardians - pointers on first and last elements of list
 */
class DoubleLinkedList : public List
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void add(int newValue, int position);
    int remove(int position);
    int extract(int position);
    void print();
    bool empty();
    int length();
    int search(int value);
    void clear();

private:
    /**
     * @brief Node of double linked list
     */
    class ListNode
    {
    public:
        ListNode(int newValue, ListNode *previusNode, ListNode *nextNode);
        int value;
        ListNode *next;
        ListNode *previous;
    };

    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int size = 0;
};
