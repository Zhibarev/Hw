#include "pointertest.h"

int main()
{
    PointerTest test;
    QTest::qExec(&test);
    return 0;
}
