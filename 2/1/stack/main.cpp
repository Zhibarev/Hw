#include "calculatortest.h"
#include "testarraystack.h"
#include "testlinkedstack.h"

int main()
{
    CalculatorTest testCalc;
    QTest::qExec(&testCalc);
    ArrayStackTest testArrayStack;
    QTest::qExec(&testArrayStack);
    LinkedStackTest testLinkedStack;
    QTest::qExec(&testLinkedStack);
    return 0;
}
