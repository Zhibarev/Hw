#pragma once
#include "sort.h"

class SelectionSort: public Sort
{
public:
    SelectionSort(){}
    void sort(int *array, int first, int last);
    ~SelectionSort(){}
};
