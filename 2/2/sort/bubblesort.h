#pragma once
#include "sort.h"

/**
 * @brief Class inherets from Sort
 * Realize Bubble sort
 * https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_%D0%BF%D1%83%D0%B7%D1%8B%D1%80%D1%8C%D0%BA%D0%BE%D0%BC
 */
class BubbleSort: public Sort
{
public:
    BubbleSort(){}
    void sort(int *array, int first, int last);
    ~BubbleSort(){}
};
