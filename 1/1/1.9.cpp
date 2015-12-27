#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int main() {
	printf("Enter a,n\n");
	int a = 0;
	int n = 0;
	scanf("%d %d", &a, &n);
	long long degree = 1;
	for (int i = 1; i <= abs(n); i++)
		degree *= a;
	if (n >= 0)
		printf("Result\n%lld", degree);
	else
		printf("Result\n%f", 1 / (float) degree);
	return 0;
}