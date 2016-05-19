#include <iostream>
#include "sortedset.h"

using namespace std;

int main()
{
    LinkedList *first = new LinkedList();
    for (int i = 0; i < 10; i++)
        first->add(i, i + 1);
    LinkedList *second = new LinkedList();
    for (int i = 0; i < 100; i++)
        second->add(i, i + 1);
    LinkedList *third = new LinkedList();
    for (int i = 0; i < 5; i++)
        third->add(i, i + 1);
    SortedSet set;
    set.add(first);
    set.add(second);
    set.add(third);
    ListComparator comparator;
    if (comparator.more(*first, *third))
        cout << "YES\n";
    if (comparator.equal(*set.extract(1), *third) && set.search(first) == 2 && second == set.remove(3))
        cout << "YES\n";
    set.~SortedSet();
    delete first;
    delete second;
    delete third;
    return 0;
}
