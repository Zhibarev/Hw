#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int fractions(int numerator, int denominator, int number) {
	if (numerator == (number - 1))
		printf("%d/%d", number - 1, number);
	else
		if ((float) numerator / (float) denominator >= (float) (numerator + 1) / (float) number)
			fractions(numerator + 1, number, number);
		else {
			int gcd = numerator;
			int rest = denominator;
			int unconst = 0;
			while (rest != 0) {
				unconst = rest;
				rest = gcd % rest;
				gcd = unconst;
			}
			printf("%d/%d ", numerator / gcd, denominator / gcd);
			fractions(numerator, denominator - 1, number);
		}
}

int main() {
	int number = 0;
	printf("Enter n\n");
	scanf("%d", &number);
	fractions(1, number, number);
	return 0;
}