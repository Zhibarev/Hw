#include <cstdio>
#include <cstring>
#include "stack.h"
#include "noteForm.h"
using namespace std;

int actionPriority(char element){
	if (element == '*' || element =='/')
		return 1;
	else
		return 0;
}

void infixToPrefix(char infixForm[],char prefixForm[], Stack &stack) {
	for (int j = 0; j < strlen(infixForm); j++)
		if ((infixForm[j] <= '9') && (infixForm[j] >= '0'))
			prefixForm[strlen(prefixForm)] = infixForm[j];
		else {
			if (infixForm[j] == '(')
				push(infixForm[j], stack);
			else
				if (infixForm[j] == ')') {
					while (stack.top->next->number != '(') {
						prefixForm[strlen(prefixForm)] = (char) stack.top->next->number;
						pop(stack);
					}
					pop(stack);
				}
				else {
					while ((stack.top->next != NULL) && ((((stack.top->next)->number) != '(') && (actionPriority(infixForm[j]) <= actionPriority((stack.top->next)->number)))) {
						prefixForm[strlen(prefixForm)] = (stack.top->next)->number;
						pop(stack);
					}
					push(infixForm[j], stack);
				}
		}
	while (stack.top->next != NULL) {
		prefixForm[strlen(prefixForm)] = (stack.top->next)->number;
		pop(stack);
	}
}

int calculate(int number1, int number2, char action) {
	if (action == '+')
		return (number1 + number2);
	if (action == '-')
		return (number2 - number1);
	if (action == '*')
		return (number1 * number2);
	if (action == '/')
		return (number2 / number1);
}

int prefixToResult(Stack &stack, char prefixForm[]){
	int number1 = 0;
	int number2 = 0;
	for (int i = 0; i < strlen(prefixForm); i++)
		if ((prefixForm[i] <= '9') && (prefixForm[i] >= '0'))
			push(prefixForm[i] - '0', stack);
		else {
			number1 = stack.top->next->number;
			pop(stack);
			number2 = stack.top->next->number;
			pop(stack);
			push(calculate(number1, number2, prefixForm[i]), stack);
		}
	return stack.top->next->number;
}