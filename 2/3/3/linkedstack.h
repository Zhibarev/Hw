#pragma once
#include "stack.h"

template <typename T>
///@brief template linked stack
class LinkedStack : public Stack<T>
{

public:
    LinkedStack(){}
    void push(const T &newValue);
    T &pop();
    bool isEmpty() const;
    int length() const;
    T &top() const;
    ~LinkedStack();

private:
    class StackNode
    {
    public:
        StackNode(const T &newValue, StackNode *nextNode);
        T value;
        StackNode *next;
    };
    int size = 0;
    StackNode *topNode = nullptr;
};



template <typename T>
LinkedStack<T>::StackNode::StackNode(const T &newValue, StackNode *nextNode)
{
    value = newValue;
    next = nextNode;
}

template <typename T>
void LinkedStack<T>::push(const T &newValue)
{
    topNode = new StackNode(newValue, topNode);
    size++;
}

template <typename T>
T &LinkedStack<T>::pop()
{
    T value = topNode->value;
    StackNode *removedNode = topNode;
    topNode = topNode->next;
    delete removedNode;
    size--;
    return value;
}

template <typename T>
bool LinkedStack<T>::isEmpty() const
{
    return topNode == nullptr;
}

template <typename T>
int LinkedStack<T>::length() const
{
    return size;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    while (!isEmpty())
        pop();
}

template <typename T>
T &LinkedStack<T>::top() const
{
    return topNode->value;
}

