#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void qsort(int begin, int end, char array[]) {
	char median = array[(begin + end) / 2];
	int i = begin;
	int j = end;
	while (i < j) {
		while (array[i] < median)
			i++;
		while (array[j] > median)
			j--;
		if (i <= j) {
			swap(array[i], array[j]);
            i++;
            j--;
		}
	}
	if (j > begin)
		qsort(begin, j, array);
	if (i < end)
		qsort(i, end, array);
}

int main() {
	printf("Enter number\n");
	char number[10000];
	scanf("%s", &number);
	qsort(0, strlen(number) - 1, number);
	int countOfZero = 0;
	while (strlen(number) != 1 && (countOfZero < strlen(number)) && (number[countOfZero] == '0'))
		countOfZero++;
	printf("Min reshuffle\n");
	for (int j = countOfZero; j < strlen(number); j++) {
		printf("%c", number[j]);
		if (j == countOfZero)
			for (int i = 0; i < countOfZero; i++)
				printf("0");
	}
	return 0;
}