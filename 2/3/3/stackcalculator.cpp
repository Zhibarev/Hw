#include "stackcalculator.h"
#include "linkedstack.h"
#include <cstring>
#include <iostream>

double StackCalculator::calculator(const char *expression)
{
    Stack<char> *operations = new LinkedStack<char>();
    Stack<double> *numbers = new LinkedStack<double>();
    int size = strlen(expression);
    int intPart = 0;
    double fractionPart = 0;
    int tenDegree = 0;
    int i = 0;
    while (i < size)
    {
        if (i == 0 && expression[i] == '-')
            numbers->push(0);
        if ('0' <= expression[i] && expression[i] <= '9')
        {
            intPart = 0;
            while ('0' <= expression[i] && expression[i] <= '9')
            {
                intPart = intPart * 10 + expression[i] - '0';
                i++;
            }
            fractionPart = 0;
            if (expression[i] == '.' || expression[i] == ',')
            {
                i++;
                tenDegree = 10;
                while ('0' <= expression[i] && expression[i] <= '9')
                {
                        fractionPart += ((double)(expression[i] - '0')) / tenDegree;
                    if (tenDegree * 10 > tenDegree)
                        tenDegree *= 10;
                    i++;
                }
            }
            numbers->push((double)intPart + fractionPart);
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
    double result = numbers->pop();
    delete numbers;
    return result;
}

double StackCalculator::calculate(double firstNumber, double secondNumber, char action)
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

int StackCalculator::priority(char action)
{
    if (action == '+' || action == '-')
        return 1;
    else
        return 2;
}
