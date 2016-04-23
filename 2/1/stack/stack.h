#pragma once

///@brief interface for int stack
class Stack
{
public:
    virtual void push(int newValue) = 0;
    /**
     * @brief pop top element
     * @return top element or 0 if stack is empty
     */
    virtual int pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual int length() const = 0;
    virtual int top() const = 0;
    virtual void print() const = 0;
    virtual ~Stack(){}
};
