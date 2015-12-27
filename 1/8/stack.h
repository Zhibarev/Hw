#pragma once

struct StackNode{
	int number;
	StackNode* next;
};

struct Stack{
	StackNode* top;
};

Stack createStack();

void push(int addNumber, Stack &stack);

int pop(Stack &stack);

bool isEmpty(Stack &stack);

void clearStack(Stack &stack);