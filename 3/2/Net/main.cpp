#include "Test/computertest.h"
#include "Test/nettest.h"

int main()
{
    ComputerTest test;
    QTest::qExec(&test);
    NetTest netTest;
    QTest::qExec(&netTest);
    return 0;
}
