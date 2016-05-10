#pragma once
#include "fileprinter.h"

///@brief Class to print to console
class ConsolePrinter: public FilePrinter
{
public:
    ConsolePrinter(): FilePrinter(stdout){}
    ~ConsolePrinter(){}
};
