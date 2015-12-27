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
	printf("Enter first and second string\n");
	char string1[10000];
	char string2[10000];
	scanf("%s %s", &string1, &string2);
	if (strlen(string1) != strlen(string2)) {
		printf("No");
		return 0;
	}
	qsort(0, strlen(string1) - 1, string1);
	qsort(0, strlen(string2) - 1, string2);
	int i = 0;
	while ((i < strlen(string1)) && (string1[i] == string2[i]))
		i++;
	if (i >= strlen(string1))
		printf("Yes");
	else
		printf("No");
	return 0;
}