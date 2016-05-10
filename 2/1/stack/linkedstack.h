#pragma once
#include "stack.h"

///@brief Linked Stack
class LinkedStack : public Stack
{
public:
    LinkedStack(){}
    void push(int newValue);
    int pop();
    bool isEmpty() const;
    int length() const;
    void print() const;
    int top() const;
    ~LinkedStack();
private:
    class StackNode
    {
    public:
        StackNode(int newValue, StackNode *nextNode);
        int value;
        StackNode *next;
    };
    int size = 0;
    StackNode *topNode = nullptr;
};
