#include <cstdio>
using namespace std;

int main() {
	printf("Enter N and array\n");
	int number;
	scanf("%d", &number);
	int **array = new int* [number];
	for (int i = 0; i < number; i++)
		array[i] = new int[number];
	for (int i = number - 1; i >= 0; i--)
		for (int j = 0; j < number; j++)
			scanf("%d", &array[j][i]);
	printf("Circle\n");
	for (int j = 0; j < number / 2; j++) {
		for (int i = j; i <= number - 1 - j; i++)
			printf("%d ", array[j][i]);
		for (int i = j + 1; i <= number - 1 - j; i++)
			printf("%d ", array[i][number - 1 - j]);
		for (int i = number - j - 2; i >= j; i--)
			printf("%d ", array[number - j - 1][i]);
		for (int i = number - j - 2; i > j; i--)
			printf("%d ", array[i][j]);
	}
	printf("%d", array[number / 2][number / 2]);
	for (int i = 0; i < number; i++)
		delete []array[i];
	delete []array;
	return 0;
}