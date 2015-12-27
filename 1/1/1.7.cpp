#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int main() {
	printf("Enter number\n");
	int max = 0;
	scanf("%d", &max);
	int number[max + 1];
	for (int i = 2; i <= max; i++)
		number[i] = 0;
	printf("Prime numbers\n");
	for (int i = 2; i <= max; i++)
		if (number[i] == 0) {
			printf("%d ", i);
			for (int j = 2; (j * i) <= max; j++)
				number[j * i] = -1;
		}
	return 0;
}