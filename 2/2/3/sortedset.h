#pragma once
#include "listcomparator.h"
#include "linkedlist.h"

///@brief Sorted set of Linked Lists
class SortedSet
{
public:
    void add(LinkedList *newList);
    LinkedList* remove(int position);
    /**
     * @brief return list from specified positon
     * @param position
     * @return list
     */
    LinkedList* extract(int position) const;
    bool empty() const;
    int length() const;
    /**
     * @brief search position of list
     * @param list
     * @return position or 0 if wasn't find
     */
    int search(LinkedList* list) const;
    void clear();
    ~SortedSet();
private:
    class Node
    {
    public:
        Node(LinkedList *newList, Node *nextNode);
        LinkedList *list;
        Node *next;
    };
    Node *head = new Node(nullptr, nullptr);
    int size = 0;
};
