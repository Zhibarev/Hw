#pragma once
#include "sort.h"

///@brief Bubblesort
class BubbleSort: public Sort
{
public:
    BubbleSort(){}
    void sort(int *array, int first, int last);
    ~BubbleSort(){}
};
