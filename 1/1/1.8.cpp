#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

long long factorialRecursive(int n) {
	if (n == 1)
		return 1;
	else
		return (n * factorialRecursive(n - 1));
}

long long factorialIterative(int n) {
	int factorial = 1;
	for (int i = 2; i <= n; i++)
			factorial *= i;
	return factorial;
}

int main() {
	printf("Enter n\n");
	int n = 0;
	scanf("%d", &n);
	printf("Enter 0 for iterative / 1 for recursive\n"); 
	int iterativeRecursive = 0;
	scanf("%d", &iterativeRecursive);
	long long result = 1;
	if (iterativeRecursive == 0)
		result = factorialIterative(n);
	else
		result = factorialRecursive(n);
	printf("Result\n%lld", result);
	return 0;
}
		
	