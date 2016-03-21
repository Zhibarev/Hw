#pragma once
#include "sort.h"


class InsertSort: public Sort
{
public:
    InsertSort(){}
    void sort(int *array, int first, int last);
    ~InsertSort(){}
};
