#pragma once
#include "sort.h"

class QuickSort: public Sort
{
public:
    QuickSort(){}
    void sort(int *array, int first, int last);
    ~QuickSort(){}
};
