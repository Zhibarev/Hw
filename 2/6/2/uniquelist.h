#pragma once

#include "linkedlist.h"
#include "uniquieexeptions.h"

class UniqueList: public LinkedList
{
public:
    ~UniqueList(){}

    /**
     * @brief wrapper of LinkedList's add
     * Throw OutOfRange if add on wrong position
     * Throw AlreadyInclude if value is already include to list
     * @param value
     * @param position
     */
    void addUnique(int value, int position);
    /**
     * @brief wrapper of LinkedList's remove
     * Throw OutOfRange if remove from wrong position
     * @param position
     * @return value
     */
    int removeUnique(int position);
    /**
     * @brief wrapper of LinkedList's extract
     * Throw OutOfRange if extract from wrong position
     * @param position
     * @return value
     */
    int extractUnique(int position);
};
