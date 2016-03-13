#pragma once
#include "stack.h"

class LinkedStack : public Stack
{
public:
    LinkedStack(){}
    void push(int newValue);
    int pop();
    bool isEmpty();
    int length();
    void print();
    int top();
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
