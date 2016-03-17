#include "sortedset.h"

SortedSet::Node::Node(ListComparator *newList, Node *nextNode)
{
    next = nextNode;
    list = newList;
}

SortedSet::~SortedSet()
{
    clear();
    delete head;
}

int SortedSet::length()
{
    return size;
}

void SortedSet::add(ListComparator *newList)
{
    Node *runner = head;
    while (runner->next != nullptr && *runner->next->list < *newList)
        runner = runner->next;
    runner->next = new Node(newList, runner->next);
    size++;
}

ListComparator* SortedSet::remove(int position)
{
    if (position > size)
        return 0;
    Node *runner = head;
    for (int i = 1; i < position; i++)
        runner = runner->next;
    Node *newNext = runner->next->next;
    ListComparator* removeList = runner->next->list;
    delete runner->next;
    runner->next = newNext;
    size--;
    return removeList;
}

ListComparator* SortedSet::extract(int position)
{
    if (position > size)
        return 0;
    Node *runner = head;
    for (int i = 1; i <= position; i++)
        runner = runner->next;
    return runner->list;
}

bool SortedSet::empty()
{
    return head->next == nullptr;
}

int SortedSet::search(ListComparator *list)
{
    Node *runner = head;
    int position = 0;
    do
    {
        runner = runner->next;
        position++;
    } while (runner != nullptr && runner->list != list);
    return position;
}

void SortedSet::clear()
{
    while (head->next != nullptr)
        remove(1);
}
