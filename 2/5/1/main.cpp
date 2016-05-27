#include <fstream>
#include <iostream>
#include <string>
#include "tree.h"
#include "treetest.h"

using namespace std;

int main()
{
    TreeTest test;
    QTest::qExec(&test);
    return 0;
}
