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
	printf("Expression in prefix form\n");
	char prefixForm[10000];
	infixToPrefix(infixForm, prefixForm, stack);
	for (int i = 0; i < strlen(prefixForm); i++)
		printf("%c", prefixForm[i]);
	return 0;
}
