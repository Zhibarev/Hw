#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int fibonacciRecurative(int number, int fibonacci[]) {
	if (fibonacci[number] == 0)
		fibonacci[number] = fibonacciRecurative(number - 1, fibonacci) + fibonacciRecurative(number - 2, fibonacci);
	return fibonacci[number];
}

int fibonacciIterative(int number) {
	int fibonacciPrevius = 1;
	int fibonacciCurrent = 1;
	for (int i = 2; i <= number; i++) {
		fibonacciCurrent = fibonacciCurrent + fibonacciPrevius;
		fibonacciPrevius = fibonacciCurrent - fibonacciPrevius;
	}
	return fibonacciCurrent;
}

int main() {
	printf("Enter fibonacci number\n");
	int number = 0;
	scanf("%d", &number);
	printf("Enter 0 for recursive / 1 for iterative\n");
	int iterativeRecursive = 0;
	scanf("%d", &iterativeRecursive);
	if (iterativeRecursive == 0) {
		int fibonacci[number + 1];
		fibonacci[0] = 1;
		fibonacci[1] = 1;
		for (int i = 2; i <= number; i++)
			fibonacci[i] = 0;
		printf("Result\n%d", fibonacciRecurative(number, fibonacci));
	}
	else
		printf("Result\n%d", fibonacciIterative(number));
	return 0;
}
	
	