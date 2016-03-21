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
    if (size == 0)
        return 0;
    size--;
    return array[size];
}

bool ArrayStack::isEmpty()
{
    return size == 0;
}

void ArrayStack::print()
{
    for (int i = size - 1; i >= 0; i--)
        std::cout << array[i] << " ";
    std ::cout << '\n';
}

int ArrayStack::length()
{
    return size;
}

ArrayStack::~ArrayStack()
{
    delete []array;
}

int ArrayStack::top()
{
    if (size == 0)
        return 0;
    return array[size - 1];
}
