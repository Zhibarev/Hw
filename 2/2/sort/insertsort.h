#pragma once
#include "sort.h"

/**
 * @brief Class inherets from Sort
 * Realize Insertion sort
 * https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B2%D1%81%D1%82%D0%B0%D0%B2%D0%BA%D0%B0%D0%BC%D0%B8
 */
class InsertSort: public Sort
{
public:
    InsertSort(){}
    void sort(int *array, int first, int last);
    ~InsertSort(){}
};
