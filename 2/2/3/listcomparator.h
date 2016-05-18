#pragma once
#include "linkedlist.h"

///@brief Class for compare Linked lists based on their size
class ListComparator
{
public:
    ListComparator(){}
    bool less(const LinkedList &first, const LinkedList &second) const;
    bool more(const LinkedList &first, const LinkedList &second) const;
    bool equal(const LinkedList &first, const LinkedList &second) const;
    ~ListComparator(){}
};
