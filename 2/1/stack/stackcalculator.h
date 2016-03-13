#pragma once

class StackCalculator
{
public:
    int calculator(char *expression);
private:
    int calculate(int firstNumber, int secondValue, char action);
    bool isOperation(char symbol);
    int priority(char symbol);
};
