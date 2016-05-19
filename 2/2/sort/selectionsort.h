#pragma once
#include "sort.h"

/**
 * @brief Class inherets from Sort
 * Realize Selection sort
 */
class SelectionSort: public Sort
{
public:
    SelectionSort(){}
    void sort(int *array, int first, int last);
    ~SelectionSort(){}
};
