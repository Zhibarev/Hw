#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void splitSum(int restSum, int maxNumber, int NumberOfNumbers, int currentSplit[]) {
	if ((restSum >= 0) && (maxNumber > 0))
		if (restSum == 0) {
			for (int i = 1; i <= NumberOfNumbers; i++)
				printf("%d ", currentSplit[i]);
			printf("\n");
		}
		else {
				splitSum(restSum, maxNumber - 1, NumberOfNumbers, currentSplit);
				if ((restSum - maxNumber) >= 0) {
					currentSplit[NumberOfNumbers + 1] = maxNumber;
					splitSum(restSum - maxNumber, maxNumber, NumberOfNumbers + 1, currentSplit);
				}
		}
}

int main() {
	int number = 0;
	printf("Enter N\n");
	scanf("%d", &number);
	int split[number + 1];
	splitSum(number, number, 0, split);
	return 0;
}