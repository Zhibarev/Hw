#include "sorttest.h"
#include <iostream>

using namespace std;

int main()
{
    SortTest test;
    QTest::qExec(&test);
    return 0;
}
