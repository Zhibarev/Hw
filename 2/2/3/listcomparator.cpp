#include "listcomparator.h"

bool ListComparator::less(const LinkedList &first, const LinkedList &second) const
{
    return (first.length() < second.length());
}

bool ListComparator::more(const LinkedList &first, const LinkedList &second) const
{
    return (first.length() > second.length());
}

bool ListComparator::equal(const LinkedList &first, const LinkedList &second) const
{
    return (first.length() == second.length());
}
