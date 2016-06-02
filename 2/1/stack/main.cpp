#include <iostream>
#include "stackcalculator.h"

using namespace std;

int main()
{
    StackCalculator calculator;
    cout << "Enter expression\n";
    char *expression = new char[1000];
    cin >> expression;
    cout << "Result\n" << calculator.calculator(expression);
    delete expression;
    return 0;
}
