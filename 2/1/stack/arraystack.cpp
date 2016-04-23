#include "arraystack.h"
#include <iostream>

ArrayStack::ArrayStack(int newSize)
{
    maxSize = newSize;
    array = new int[maxSize];
}

void ArrayStack::push(int newValue)
{
    if (size < maxSize) {
        array[size] = newValue;
        size++;
    }
}

int ArrayStack::pop()
{
    if (isEmpty())
        return 0;
    size--;
    return array[size];
}

bool ArrayStack::isEmpty() const
{
    return size == 0;
}

void ArrayStack::print() const
{
    for (int i = size - 1; i >= 0; i--)
        std::cout << array[i] << " ";
    std ::cout << '\n';
}

int ArrayStack::length() const
{
    return size;
}

ArrayStack::~ArrayStack()
{
    delete []array;
}

int ArrayStack::top() const
{
    if (isEmpty())
        return 0;
    return array[size - 1];
}
