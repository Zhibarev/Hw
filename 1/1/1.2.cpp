#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int main() {
	printf("Enter a,b\n");
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int result = 1;
	if (b == 0)
		printf("Result\nb=0!!!");
	else {
		while (abs(result * b) < abs(a))
			result++;
		if ((b * a) > 0)
			if (a > 0)
				printf("Result\n%d", result - 1);
			else
				printf("Result\n%d", result);
		else
			printf("Result\n%d", -result);
	}
	return 0;
}
		
	