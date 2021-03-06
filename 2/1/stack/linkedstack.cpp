#include "linkedstack.h"
#include <iostream>

LinkedStack::StackNode::StackNode(int newValue, StackNode *nextNode)
{
    value = newValue;
    next = nextNode;
}

void LinkedStack::push(int newValue)
{
    topNode = new StackNode(newValue, topNode);
    size++;
}

int LinkedStack::pop()
{
    if (isEmpty())
        return 0;
    int value = topNode->value;
    StackNode *removedNode = topNode;
    topNode = topNode->next;
    delete removedNode;
    size--;
    return value;
}

bool LinkedStack::isEmpty() const
{
    return topNode == nullptr;
}

void LinkedStack::print() const
{
    StackNode *runner = topNode;;
    while (runner != nullptr)
    {
        std::cout << runner->value << ' ';
        runner = runner->next;
    }
    std::cout << '\n';
}

int LinkedStack::length() const
{
    return size;
}

LinkedStack::~LinkedStack()
{
    while (!isEmpty())
        pop();
}

int LinkedStack::top() const
{
    if (isEmpty())
        return 0;
    return topNode->value;
}
