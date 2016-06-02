#include <printertest.h>
#include <cstdio>
#include <iostream>

int main()
{
    PrinterTest test;
    QTest::qExec(&test);
    return 0;
}

