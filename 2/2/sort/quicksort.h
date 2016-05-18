#pragma once
#include "sort.h"

///@brief Quicksort
class QuickSort: public Sort
{
public:
    QuickSort(){}
    void sort(int *array, int first, int last);
    ~QuickSort(){}
};
