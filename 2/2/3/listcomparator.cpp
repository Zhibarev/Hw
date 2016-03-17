#include "listcomparator.h"

bool ListComparator::operator<(const LinkedList &list)
{
    if (this.size() < list.size())
        return true;
    return false;
}

bool ListComparator::operator>(const LinkedList &list)
{
    if (this.size() > list.size())
        return true;
    return false;
}

bool ListComparator::operator==(const LinkedList &list)
{
    if (this.size() == list.size())
        return true;
    return false;
}
