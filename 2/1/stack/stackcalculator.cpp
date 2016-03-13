#include "stackcalculator.h"
#include "linkedstack.h"
#include <cstring>
#include <iostream>

int StackCalculator::calculator(char *expression)
{
    Stack *operations = new LinkedStack();
    Stack *numbers = new LinkedStack();
    int size = strlen(expression);
    int number = 0;
    int i = 0;
    while (i < size)
    {
        if ('0' <= expression[i] && expression[i] <= '9')
        {
            number = 0;
            while ('0' <= expression[i] && expression[i] <= '9')
            {
                number = number * 10 + expression[i] - '0';
                i++;
            }
            numbers->push(number);
        }
        if (isOperation(expression[i]))
        {
            if(!operations->isEmpty() && operations->top() != '(' && priority(expression[i]) <= priority(operations->top()))
                numbers->push(calculate(numbers->pop(), numbers->pop(), operations->pop()));
            operations->push(expression[i]);
        }
        if (expression[i] == '(')
            operations->push(expression[i]);
        if (expression[i] == ')') {
            while (operations->top() != '(')
                numbers->push(calculate(numbers->pop(), numbers->pop(), operations->pop()));
            operations->pop();
        }
        i++;
    }
    while (!operations->isEmpty())
        numbers->push(calculate(numbers->pop(), numbers->pop(), operations->pop()));
    delete operations;
    int result = numbers->pop();
    delete numbers;
    return result;
}

int StackCalculator::calculate(int firstNumber, int secondNumber, char action)
{
    switch (action)
    {
        case '+':
            return firstNumber + secondNumber;
        break;
        case '*':
            return firstNumber * secondNumber;
        break;
        case '/':
            if (secondNumber != 0)
                return firstNumber / secondNumber;
        break;
        case '-':
            return firstNumber - secondNumber;
        break;
    }
    return 0;
}


bool StackCalculator::isOperation(char symbol)
{
    return (symbol == '+' || symbol == '*' || symbol == '/' || symbol == '-');
}

int StackCalculator::priority(char symbol)
{
    if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 2;
}
