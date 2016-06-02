#include <iostream>
#include "sortedsettest.h"

using namespace std;

int main()
{
    SortedSetTest test;
    QTest::qExec(&test);
    return 0;
}
