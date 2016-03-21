#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack(int newSize);
    void push(int newValue);
    int pop();
    bool isEmpty();
    int length();
    void print();
    int top();
    ~ArrayStack();
private:
    int maxSize;
    int size = 0;
    int *array;
};
