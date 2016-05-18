#pragma once
#include "sort.h"

///@brief Heapsort
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
