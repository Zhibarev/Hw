#pragma once

template <typename T>
///@brief interface for template class stack
class Stack
{

public:
    virtual void push(const T &newValue) = 0;
    virtual T &pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual int length() const = 0;
    virtual T &top() const = 0;
    virtual ~Stack(){}
};
