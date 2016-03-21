#include "fileprinter.h"

FilePrinter::FilePrinter(FILE *outputFile)
{
    output = outputFile;
}

void FilePrinter::print(int **array, int size)
{
    for (int j = 0; j < size / 2; j++)
    {
        for (int i = j; i <= size - 1 - j; i++)
            fprintf(output, "%d ", array[j][i]);
        for (int i = j + 1; i <= size - 1 - j; i++)
            fprintf(output, "%d ", array[i][size - 1 - j]);
        for (int i = size - j - 2; i >= j; i--)
            fprintf(output, "%d ", array[size - j - 1][i]);
        for (int i = size - j - 2; i > j; i--)
            fprintf(output, "%d ", array[i][j]);
    }
    fprintf(output, "%d", array[size / 2][size / 2]);
}
