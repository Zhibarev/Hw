#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long binaryDegree(int number, int degree) {
	long long numberInHalfDegree = 0;
	long long result = 1;
	if (degree == 1)
		return number;
	numberInHalfDegree = binaryDegree(number, degree / 2);
	result = numberInHalfDegree * numberInHalfDegree;
	if (degree % 2 == 1)
		result *= number;
	return result;
}

int main() {
	printf("Enter number and degree\n");
	int degree = 0;
	int number = 0;
	scanf("%d %d", &number, &degree);
	if (degree == 0)
		printf("Result\n1");
	else
		if (degree > 0)
			printf("Result\n%lld", binaryDegree(number, degree));
		else
			printf("Result\n%f", 1 / (float)binaryDegree(number, -degree));
	return 0;
}