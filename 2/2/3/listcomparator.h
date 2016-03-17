#include "linkedlist.h"

class ListComparator: public LinkedList
{
public:
    ListComparator(){}
    bool operator>(const LinkedList &list);
    bool operator<(const LinkedList &list);
    bool operator==(const LinkedList &list);
    ~ListComparator(){}
};
