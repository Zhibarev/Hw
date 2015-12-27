#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int maxVertex(int heap[], int index1, int index2) {
	if (heap[index1] > heap[index2])
		return index1;
	else
		return index2;
}

void siftUp(int heap[], int number) {
	while ((number != 1) && (heap[number] > heap[number / 2])) {
		swap(heap[number], heap[number / 2]);
		number = number / 2;
	}
}

void siftDown(int heap[], int heapSize, int current) {
	int child1 = current * 2;
	int child2 = current * 2 + 1;
	while (child2 <= heapSize) {
		if (heap[current] < heap[maxVertex(heap, child1, child2)]) {
			swap(heap[current], heap[maxVertex(heap, child1, child2)]);
			current = maxVertex(heap, child1, child2);
		}
		else
			current = heapSize;
		child1 = current * 2;
		child2 = current * 2 + 1;
	}
	if ((child1 == heapSize) && (heap[current] < heap[child1]))
		swap(heap[current], heap[child1]);
}

void heapSort(int array[], int number) {
	for (int i = 1; i <= number; i++)
		siftUp(array, i);
	for (int i = number; i > 1; i--) {
		swap(array[i], array[1]);
		siftDown(array, i - 1, 1);
	}	
}

int main() {
	printf("Enter number of elements and array\n");
	int number = 0;
	scanf("%d", &number);
	int array[number + 1];
	for (int i = 1; i <= number; i++)
		scanf("%d", &array[i]);
	heapSort(array, number);
	printf("Sorted array\n");
	for (int i = 1; i <= number; i++)
		printf("%d ", array[i]);
	return 0;
}
	