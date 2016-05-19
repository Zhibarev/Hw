#pragma once
#include "sort.h"

/**
 * @brief Class inherets from Sort
 * Realize QuickSort
 */
class QuickSort: public Sort
{
public:
    QuickSort(){}
    void sort(int *array, int first, int last);
    ~QuickSort(){}
};
