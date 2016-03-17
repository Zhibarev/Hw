#pragma once

using namespace std;

class List
{
public:
    virtual void add(int newValue) = 0;
    virtual bool remove(int removedValue) = 0;
    virtual void print() = 0;
    virtual bool empty() = 0;
    virtual bool search(int searchedValue) = 0;
    virtual int size() = 0;
    virtual ~List(){}
};
