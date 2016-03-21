#include "insertsort.h"
#include <algorithm>

void InsertSort::sort(int *array, int first, int last)
{
    int j = 0;
    for (int i = first + 1; i <= last; i++)
    {
        j = i;
        while (j > first && array[j] < array[j - 1])
        {
            std::swap(array[j], array[j - 1]);
            j--;
        }
    }

}
