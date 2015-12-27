#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main () {
	int const maxSum = 27;
	int sum[maxSum + 1];
	for (int i = 0; i <= maxSum; i++)
		sum[i] = 0;
	int const maxNumeric = 9;
	for (int i = 0; i <= maxNumeric; i++)
		for (int j = 0; j <= maxNumeric; j++)
			for (int c = 0; c <= maxNumeric; c++)
				sum[i + j + c]++;
	int numberLuck = 0;
	for (int i = 0; i <= maxSum; i++)
		numberLuck += sum[i] * sum[i];
	printf("Number of lucky tickets\n%d", numberLuck);
	return 0;
}