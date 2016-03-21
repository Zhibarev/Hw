#pragma once

class Stack
{
public:
    virtual void push(int newValue) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() = 0;
    virtual int length() = 0;
    virtual int top() = 0;
    virtual void print() = 0;
    virtual ~Stack(){}
};
