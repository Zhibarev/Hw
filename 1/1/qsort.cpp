#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

void qsort(int begin, int end, int array[]) {
	int median = array[(begin + end) / 2];
	int i = begin;
	int j = end;
	while (i < j) {
		while (array[i] < median)
			i++;
		while ((j > i) && (array[j] > median))
			j--;
		if (i != j)
			swap(array[i], array[j]);
		i++;
		j--;
	}
	if (j > begin)
		qsort(begin, j, array);
	if (i < end)
		qsort(i, end, array);
}

int main() {
	printf("Enter number of elements and array\n");
	int numberElements = 0;
	scanf("%d", &numberElements);
	int array[numberElements + 1];
	for (int i = 1;i <= numberElements;i++)
		scanf("%d", &array[i]);
	qsort(1, numberElements, array);
	printf("Sorted array\n");
	for (int i = 1;i <= numberElements;i++)
		printf("%d ", array[i]);
	return 0;
}
		
	