#include "listcomparator.h"

bool ListComparator::operator<(const ListComparator &list)
{
    return (length() < list.length());
}

bool ListComparator::operator>(const ListComparator &list)
{
    return (length() > list.length());
}

bool ListComparator::operator==(const ListComparator &list)
{
    return (length() == list.length());
}

bool ListComparator::operator<=(const ListComparator &list)
{
    return (length() <= list.length());
}

bool ListComparator::operator>=(const ListComparator &list)
{
   return (length() >= list.length());
}
