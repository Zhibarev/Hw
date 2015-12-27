#include <cstdio>
#include <cstring>
#include "stack.h"
#include "noteForm.h"
using namespace std;

int main() {
	char infixForm[10000];
	printf("Enter expression\n");
	scanf("%s", &infixForm);
	Stack stack = creatStack();
	printf("Result\n%d", prefixToResult(stack, infixForm));
	return 0;
}







