#include "selectionsort.h"
#include <algorithm>

void SelectionSort::sort(int *array, int first, int last)
{
    int max = 0;
    for (int i = last; i > first; i--)
    {
        max = first;
        for (int j = first + 1; j <= i; j++)
            max = array[j] > array[max] ? j : max;
        std::swap(array[max], array[i]);
    }
}
