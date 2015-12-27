#include <cstdio>
#include "stack.h"
using namespace std;

Stack createStack(){
	StackNode *guardian = new StackNode{0, nullptr};
	Stack newStack = {guardian};
	return newStack;
}

void push(int addNumber, Stack &stack){
	StackNode* newElement = new StackNode{addNumber, stack.top->next};
	stack.top->next = newElement;
}

int pop(Stack &stack){
	int value = 0;
	if (stack.top->next != nullptr) {
		StackNode* top = stack.top->next;
		stack.top->next = top->next;
		value = top->number;
		delete top;
	}
	return value;
}

bool isEmpty(Stack &stack){
	return (stack.top->next == nullptr);
}

void clearStack(Stack &stack){
	while (stack.top->next != nullptr)
		pop(stack);
	delete stack.top;
}