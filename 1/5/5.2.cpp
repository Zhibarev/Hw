#include <cstdio>

using namespace std;

int main() {
	printf("Enter double number\n");
	double number = 0;
	scanf("%lf", &number);
	if (number == 0)
		printf("0.0*2^0");
	else {
	unsigned char *part = (unsigned char*) &number;
	int sign = part[7] / 128;
	int order = ((part[7] % 128) * 16 + part[6] / 16) - 1023;
	double mantissa = 1 + (double) (part[6] % 16) / 16;
	long long degreeOfTwo = 256 * 16;
	for (int i = 5; i >= 0; i--) {
		mantissa += (double) part[i] / degreeOfTwo;
		degreeOfTwo *= 256;
	}
	printf(sign ? "-%.15g*2^%d" : "+%.15g*2^%d", mantissa, order);
	}
	return 0;
}