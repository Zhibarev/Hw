#include "expression.h"

int main() {
	printf("Enter expression\n");
	if (isExpression(stdin))
		printf("True\n");
	else
		printf("False\n");
	return 0;
}