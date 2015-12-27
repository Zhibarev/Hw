#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	printf("Enter x\n");
	float x = 0;
	scanf("%f", &x);
	float x2 = x * x;
	printf("Result\n%f", ((x2 + 1) * (x2 + x) + 1));
	return 0;
}