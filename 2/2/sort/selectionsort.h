#pragma once
#include "sort.h"

/**
 * @brief Class inherets from Sort
 * Realize Selection sort
 * https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B2%D1%8B%D0%B1%D0%BE%D1%80%D0%BE%D0%BC
 */
class SelectionSort: public Sort
{
public:
    SelectionSort(){}
    void sort(int *array, int first, int last);
    ~SelectionSort(){}
};
