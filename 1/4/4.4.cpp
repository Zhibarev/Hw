#include <cstdio>
#include "sortedList.h"
using namespace std;

int main(){
	int usersCommand = 1;
	int value = 0;
	List list = createList();
	printf("Help:\n0 - exit\n1 - add a value to sorted list, then you must enter value\n2 - remove a value from sorted list, then you must enter value\n3 - print list\n");
	while (usersCommand != 0){
		printf("\nEnter command\n");
		scanf("%d", &usersCommand);
		if (usersCommand == 1){
			scanf("%d", &value);
			add(value, list);
		}
		if (usersCommand == 2){
			scanf("%d", &value);
			remove(value, list);
		}
		if (usersCommand == 3) {
			printf("List\n");
			printList(list);
		}
	}
	clearList(list);
	return 0;
}