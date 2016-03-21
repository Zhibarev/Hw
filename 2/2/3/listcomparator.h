#include "linkedlist.h"

class ListComparator: public LinkedList
{
public:
    ListComparator(){}
    bool operator>(const ListComparator &list);
    bool operator<(const ListComparator &list);
    bool operator==(const ListComparator &list);
    bool operator>=(const ListComparator &list);
    bool operator<=(const ListComparator &list);
    ~ListComparator(){}
};
