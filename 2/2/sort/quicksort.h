#pragma once
#include "sort.h"

/**
 * @brief Class inherets from Sort
 * Realize QuickSort
 * https://ru.wikipedia.org/wiki/%D0%91%D1%8B%D1%81%D1%82%D1%80%D0%B0%D1%8F_%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0
 */
class QuickSort: public Sort
{
public:
    QuickSort(){}
    void sort(int *array, int first, int last);
    ~QuickSort(){}
};
