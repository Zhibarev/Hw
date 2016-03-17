#pragma once

using namespace std;

class List
{
public:
    virtual void add(int newValue, int position) = 0;
    virtual int remove(int position) = 0;
    virtual int extract(int position) const = 0;
    virtual void print() const = 0;
    virtual bool empty() const = 0;
    virtual int length() const = 0;
    virtual int search(int value) const = 0;
    virtual ~List(){}
};
