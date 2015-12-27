#include <cstdio>
#include "clist.h"
using namespace std;

int main(){
	printf("Enter n and m\n");
	int number = 0;
	int curse = 0;
	scanf("%d %d", &number, &curse);
	List list = createList(1);
	for (int i = 2; i <= number; i++)
		add(i, list);
	printf("Last Warrior\n%d", last(list, curse));
	clearList(list);
	return 0;
}