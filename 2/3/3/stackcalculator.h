#pragma once

///@brief Stack Calculator
class StackCalculator
{
public:
    /**
     * @brief calculate expression in infix form
     * @param expression
     * @return result
     */
    double calculator(const char *expression);

private:
    double calculate(double firstNumber, double secondNumber, char action);
    bool isOperation(char symbol);
    /**
     * @brief return priority of action ('/', '*' - 2 , '-', '+' - 1)
     * @param symbol
     * @return priority
     */
    int priority(char action);
};
