#include <iostream>
#include <fstream>
#include "stringList.h"
#include "phonebook.h"
#include <cstring>

using namespace std;

int main() {
	List phonebook  = readFromFile();
	int usersCommand = 1;
	char phoneNumber[100];
	char entredName[100];
	printf("Commands:\n0 - exit\n1 - add\n2 - find number by name\n3 - find name by number\n4 - save to phonebook\n");
	enum {exit, addToPhonebook, numberByName, nameByNumber, save};
	while (usersCommand != exit) {
		printf("Enter command\n");
		scanf("%d", &usersCommand);
		switch (usersCommand) {
			case addToPhonebook:
			printf("Enter name and number\n");
			scanf("%s %s", &entredName, &phoneNumber);
			add(entredName, phoneNumber, phonebook);
			break;
			case numberByName:
				printf("Enter name\n");
				scanf("%s", &entredName);
				if (findNumber(entredName, phonebook) == nullptr)
					printf("Not found\n");
				else
					printf("%s\n", findNumber(entredName, phonebook));
			break;
			case nameByNumber:
				printf("Enter number\n");
				scanf("%s", &phoneNumber);
				if (findName(phoneNumber, phonebook) == nullptr)
					printf("Not found");
				else
					printf("%s\n", findName(phoneNumber, phonebook));
			break;
			case save:
				saveToFile(phonebook);
			break;
		}
	}
	clearList(phonebook);
	return 0;
}