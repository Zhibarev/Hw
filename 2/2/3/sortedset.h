#include "listcomparator.h"

class SortedSet: public ListComparator
{
public:
    SortedSet();
    void addList(ListComparator *newList);
    bool removeList(ListComparator *removedList);
    void searchList(const ListComparator *searchedList);
    bool isEmpty();
    int sizeSet();
private:
    class Node
    {
    public:
        Node(int newValue, Node *nextNode);
        ListComparator list;
        Node *next;
    };
    int size;
};
