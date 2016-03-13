#include "listNode.h"

ListNode::ListNode(int number, ListNode *next)
{
    value = number;
    next = nextNode;
}

int ListNode::value()
{
    return value;
}

void ListNode::changeValue(int number)
{
    value = number;
}

ListNode* ListNode::nextNode()
{
    return nextNode;
}

void ListNode::changeNext(Listnode* newNext)
{
    nextNode = newNext;
}
