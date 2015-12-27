#include <cstdio>
#include <cstring>
#include "stack.h"
#include "noteForm.h"
using namespace std;

int main() {
	char infixForm[10000];
	Stack stack = creatStack();
	printf("Enter expression in index form\n");
	scanf("%s", &infixForm);
	char prefixForm[10000];
	infixToPrefix(infixForm, prefixForm, stack);
	printf("Result\n%d", prefixToResult(stack, prefixForm));
	return 0;
}
