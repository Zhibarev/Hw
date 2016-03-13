#include <iostream>
#include "list.h"

class ListNode
{
public:
    ListNode(int number, ListNode *next)
    {
        value = number;
        next = nextNode;
    }

    int value()
    {
        return value;
    }

    void changeValue(int number)
    {
        value = number;
    }

    ListNode* nextNode()
    {
        return nextNode;
    }

    void changeNext(Listnode* newNext)
    {
        nextNode = newNext;
    }
private:
    int value;
    ListNode *nextNode;
};

List::List()
{

}
