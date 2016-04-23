#include "sortedset.h"

SortedSet::Node::Node(LinkedList *newList, Node *nextNode)
{
    next = nextNode;
    list = newList;
}

SortedSet::~SortedSet()
{
    clear();
    delete head;
}

int SortedSet::length() const
{
    return size;
}

void SortedSet::add(LinkedList *newList)
{
    ListComparator comparator;
    Node *runner = head;
    while (runner->next != nullptr && comparator.less(*runner->next->list, *newList))
        runner = runner->next;
    runner->next = new Node(newList, runner->next);
    size++;
}

LinkedList* SortedSet::remove(int position)
{
    if (position > size)
        return 0;
    Node *runner = head;
    for (int i = 1; i < position; i++)
        runner = runner->next;
    Node *newNext = runner->next->next;
    LinkedList* removeList = runner->next->list;
    delete runner->next;
    runner->next = newNext;
    size--;
    return removeList;
}

LinkedList* SortedSet::extract(int position) const
{
    if (position > size)
        return 0;
    Node *runner = head;
    for (int i = 1; i <= position; i++)
        runner = runner->next;
    return runner->list;
}

bool SortedSet::empty() const
{
    return head->next == nullptr;
}

int SortedSet::search(LinkedList *list) const
{
    Node *runner = head->next;
    int position = 1;
    while (runner != nullptr && runner->list != list)
    {
        runner = runner->next;
        position++;
    }
    return runner != nullptr ? position : 0;
}

void SortedSet::clear()
{
    while (head->next != nullptr)
        remove(1);
}
