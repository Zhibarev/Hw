#include "listcomparator.h"

class SortedSet
{
public:
    void add(ListComparator *newList);
    ListComparator* remove(int position);
    ListComparator* extract(int position);
    bool empty();
    int length();
    int search(ListComparator* list);
    void clear();
    ~SortedSet();
private:
    class Node
    {
    public:
        Node(ListComparator *newList, Node *nextNode);
        ListComparator *list;
        Node *next;
    };
    Node *head = new Node(nullptr, nullptr);
    int size = 0;
};
