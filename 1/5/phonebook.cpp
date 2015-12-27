#include <cstdio>
#include "stringList.h"
#include "phonebook.h"
#include <cstring>

void saveToFile(List &list) {
	FILE *phonebook = fopen("phonebook.txt", "w");
	printList(list, phonebook);
	fclose(phonebook);
}

List readFromFile() {
	FILE *text = fopen("phonebook.txt", "r");
	List phonebook = createList();
	char number[100];
	char name[100];
	while(fgetc(text) != EOF) {
		fscanf(text, "%s %s", &name, &number);
		add(name, number, phonebook);
	}
	fclose(text);
	return phonebook;
}