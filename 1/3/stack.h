#pragma once

struct StackNode{
	int number;
	StackNode* next;
};

struct Stack{
	StackNode* top;
};

Stack creatStack();

void push(int addNumber, Stack &stack);

void pop(Stack &stack);

void clearStack(Stack &stack);