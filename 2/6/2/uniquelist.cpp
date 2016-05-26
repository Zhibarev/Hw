#include <iostream>
#include "uniqueList.h"

void UniqueList::addUnique(int value, int position)
{
    if (search(value) > 0)
        throw "Already include";
    if (position > length() || position < 1)
        throw "Out of range";
    add(value, position);
}

int UniqueList::removeUnique(int position)
{
    if (position > length() || position < 1)
        throw "Out of range";
    return remove(position);
}

int UniqueList::extractUnique(int position)
{
    if (position > length() || position < 1)
        throw "Out of range";
    return extract(position);
}
