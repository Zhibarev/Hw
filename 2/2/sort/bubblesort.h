#pragma once
#include "sort.h"

class BubbleSort: public Sort
{
public:
    BubbleSort(){}
    void sort(int *array, int first, int last);
    ~BubbleSort(){}
};
