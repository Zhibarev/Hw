#pragma once
#include <cstdio>
#include "printer.h"

class FilePrinter: public Printer
{
public:
    FilePrinter(FILE *outputFile);
    void print(int **array, int size);
    ~FilePrinter(){}
private:
    FILE *output;
};
