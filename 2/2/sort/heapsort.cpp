#include "heapsort.h"
#include <algorithm>
using namespace std;

void HeapSort::sort(int *array, int first, int last)
{
    for (int i = first; i <= last; i++)
        siftUp(array, i, first);
    for (int i = last; i > first; i--)
    {
        swap(array[i], array[first]);
        siftDown(array, i - 1, first);
    }
}
void HeapSort::siftUp(int *heap, int current, int first)
{
    while ((current != first) && (heap[current] > heap[current / 2]))
    {
        swap(heap[current], heap[current / 2]);
        current = current / 2;
    }
}

void HeapSort::siftDown(int *heap, int heapSize, int current)
{
    int vertex = 0;
    while ((current * 2 + 1) <= heapSize)
        if (heap[current] < heap[maxVertex(heap, current * 2, current * 2 + 1)])
        {
            vertex = maxVertex(heap, current * 2, current * 2 + 1);
            swap(heap[current], heap[vertex]);
            current = vertex;
        }
        else
            current = heapSize;
    if ((current * 2 == heapSize) && (heap[current] < heap[current * 2]))
        swap(heap[current], heap[current * 2]);
}

int HeapSort::maxVertex(int *heap, int index1, int index2)
{
    return (heap[index1] > heap[index2]) ? index1 : index2;
}

