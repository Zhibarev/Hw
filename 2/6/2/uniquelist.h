#pragma once

#include "linkedlist.h"

class UniqueList: public LinkedList
{
public:
    ~UniqueList(){}

    void addUnique(int value, int position);
    int removeUnique(int position);
    int extractUnique(int position);
};
