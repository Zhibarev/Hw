#include <iostream>
#include "uniqueList.h"

void UniqueList::addUnique(int value, int position)
{
    if (search(value) > 0)
        throw AlreadyInclude();
    if (position > length() + 1 || position < 1)
        throw OutOfRange();
    add(value, position);
}

int UniqueList::removeUnique(int position)
{
    if (position > length() + 1 || position < 1)
        throw OutOfRange();
    return remove(position);
}

int UniqueList::extractUnique(int position)
{
    if (position > length() || position < 1)
        throw OutOfRange();
    return extract(position);
}
