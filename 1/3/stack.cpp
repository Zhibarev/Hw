#include <cstdio>
#include <cstring>
#include "stack.h"
using namespace std;

Stack creatStack(){
	StackNode* guardian = new StackNode;
	guardian->number = 0;
	guardian->next = NULL;
	Stack newStack = {guardian};
	return newStack;
}

void push(int addNumber, Stack &stack){
	StackNode* newElement = new StackNode;
	newElement->number = addNumber;
	newElement->next = stack.top->next;
	stack.top->next = newElement;
}

void pop(Stack &stack){
	if (stack.top->next != NULL) {
		StackNode* top = stack.top->next;
		stack.top->next = top->next;
		delete top;
	}
}

void clearStack(Stack &stack){
	while (stack.top->next != NULL)
		pop(stack);
	delete stack.top;
}