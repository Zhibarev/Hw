#pragma once

using namespace std;

class List
{
public:
    virtual void add(int newValue, int position) = 0;
    virtual int remove(int position) = 0;
    virtual int extarct(int position) = 0;
    virtual void print() = 0;
    virtual bool empty() = 0;
    virtual int length() = 0;
    virtual int search(int value) = 0;
    virtual ~List(){}
};
