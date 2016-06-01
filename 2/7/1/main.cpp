#include "bagtest.h"

int main()
{
    BagTest test;
    QTest::qExec(&test);
    return 0;
}
