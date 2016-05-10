#pragma once
#include "stack.h"

///@brief Array stack
class ArrayStack : public Stack
{
public:
    ArrayStack(int newSize);
    void push(int newValue);
    int pop();
    bool isEmpty() const;
    int length() const;
    void print() const;
    int top() const;
    ~ArrayStack();
private:
    int maxSize = 0;
    int size = 0;
    int *array = nullptr;
};
