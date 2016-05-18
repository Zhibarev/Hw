#pragma once
#include "sort.h"

///@brief Insertion sort
class InsertSort: public Sort
{
public:
    InsertSort(){}
    void sort(int *array, int first, int last);
    ~InsertSort(){}
};
