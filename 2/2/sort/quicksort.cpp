#include "quicksort.h"
#include <algorithm>

void QuickSort::sort(int *array, int first, int last)
{
    int median = array[(first + last) / 2];
    int i = first;
    int j = last;
    while (i < j)
    {
        while (array[i] < median)
            i++;
        while (array[j] > median)
            j--;
        if (i <= j)
        {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (i < last)
        sort(array, i , last);
    if (j > first)
        sort(array, first, j);
}
