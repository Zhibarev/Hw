#include "quicksort.h"
#include "heapsort.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter size of array and array (HeapSort)\n";
    int size = 0;
    cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
        cin >> array[i];
    Sort *sorter = new HeapSort();
    sorter->sort(array, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << '\n';
    delete []array;
    delete sorter;
    cout << "Enter size of array and array (QuickSort)\n";
    size = 0;
    cin >> size;
    array = new int[size];
    for (int i = 0; i < size; i++)
        cin >> array[i];
    sorter = new QuickSort();
    sorter->sort(array, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << '\n';
    delete []array;
    delete sorter;
    return 0;
}
