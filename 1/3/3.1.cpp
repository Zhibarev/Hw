#include <cstdio>
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
	printf("Enter length of array and array\n");
	int number = 0;
	scanf("%d", &number);
	int array[number];
	for (int i = 0; i < number; i++)
		scanf("%d", &array[i]);
	qsort(0, number - 1, array);
	int i = number - 1;
	while ((i >= 1) && (array[i] != array[i - 1]))
		i--;
	if (i == 0)
		printf("No repeating elements");
	else
		printf("Max repeating element\n%d", array[i]);
	return 0;
}