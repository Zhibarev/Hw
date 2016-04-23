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
    int calculator(const char *expression);
private:
    int calculate(int firstNumber, int secondNumber, char action);
    bool isOperation(char symbol);
    /**
     * @brief return priority of action ('/', '*' - 2 , '-', '+' - 3)
     * @param symbol
     * @return priority
     */
    int priority(char action);
};
