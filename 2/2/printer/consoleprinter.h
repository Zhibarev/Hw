#pragma once
#include "fileprinter.h"

class ConsolePrinter: public FilePrinter
{
public:
    ConsolePrinter(): FilePrinter(stdout){}
    //void print(int **array, int size);
    ~ConsolePrinter(){}
};
