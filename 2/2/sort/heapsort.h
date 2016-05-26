#pragma once
#include "sort.h"

/**
 * @brief Realize Heapsort
 * Sort int array
 * Algorithm's complexity O(n * log n)
 * https://ru.wikipedia.org/wiki/%D0%9F%D0%B8%D1%80%D0%B0%D0%BC%D0%B8%D0%B4%D0%B0%D0%BB%D1%8C%D0%BD%D0%B0%D1%8F_%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0
 */
class HeapSort: public Sort
{
public:
    HeapSort(){}
    void sort(int *array, int first, int last);
    ~HeapSort(){}
private:
    void siftUp(int *heap, int current, int first);
    void siftDown(int *heap, int heapSize, int current);
    int maxVertex(int *heap, int index1, int index2);
};
