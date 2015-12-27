#include <cstdio>
#include "float.h"

int main() {
	printf("Enter float\n");
	if (isFloat(stdin))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
