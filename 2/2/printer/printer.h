#pragma once

///@brief Interface for print array NxN in spiral order
class Printer
{
public:
    virtual void print(int **array, int size) = 0;
};
