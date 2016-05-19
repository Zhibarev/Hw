#pragma once
#include "sort.h"

/**
 * @brief Class inherets from Sort
 * Realize Bubble sort
 */
class BubbleSort: public Sort
{
public:
    BubbleSort(){}
    void sort(int *array, int first, int last);
    ~BubbleSort(){}
};
