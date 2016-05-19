#pragma once
#include "sort.h"

/**
 * @brief Class inherets from Sort
 * Realize Insertion sort
 */
class InsertSort: public Sort
{
public:
    InsertSort(){}
    void sort(int *array, int first, int last);
    ~InsertSort(){}
};
