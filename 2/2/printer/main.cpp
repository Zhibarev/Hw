#include <iostream>
#include <cstdio>
#include <cstring>
#include "fileprinter.h"
#include "consoleprinter.h"

using namespace std;

int main()
{
    cout << "Enter size of array and array\n";
    int size = 0;
    cin >> size;
    int **array = new int*[size];
    for (int i = 0; i < size; i++)
        array[i] = new int[size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> array[i][j];
    cout << "Enter 1 for print in console, 2 for print in file\n";
    int usersCommand = 0;
    cin >> usersCommand;
    Printer *print;
    if (usersCommand == 1) {
        print = new ConsolePrinter();
        print->print(array, size);
    }
    else
    {
        cout << "Enter name of file\n";
        char fileName[1000];
        cin >> fileName;
        cout << fileName;
        FILE *output = fopen(fileName, "w");
        print = new FilePrinter(output);
        print->print(array, size);
        fclose(output);
    }
    delete print;
    for (int i = 0; i < size; i++)
        delete []array[i];
    delete []array;
    return 0;
}
