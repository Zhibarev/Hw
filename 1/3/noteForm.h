#pragma once

int actionPriority(char element);

void infixToPrefix(char infixForm[],char prefixForm[], Stack &stack);

int calculate(int number1, int number2, char action);

int prefixToResult(Stack &stack, char prefixForm[]);