#pragma once
#include <cstdio>
#include "printer.h"

///@brief Class to print to file
class FilePrinter: public Printer
{
public:
    FilePrinter(FILE *outputFile);
    void print(int **array, int size);
    ~FilePrinter(){}
private:
    FILE *output;
};
