#include <cstdio>
#include "stringList.h"
#include <cstring>
using namespace std;

ListString createListString() {
	ListStringNode *guardian = new ListStringNode{0, createString(nullptr), nullptr};
	ListString list = {guardian};
	return list;
}

int lengthListString(ListString list) {
	ListStringNode *current = list.first->next;
	int length = 0;
	while (current != nullptr) {
		length++;
		current = current->next;
	}
	return length;
}

void addListString(String &line, ListString &list) {
	ListStringNode *current = list.first->next;
	while(current != nullptr && !isEqual(line, current->line))
		current = current->next;
	if (current != nullptr)
		current->number++;
	else {
		ListStringNode *newElement = new ListStringNode{1, line, list.first->next};
		list.first->next = newElement;
	}
}

bool isListEmpty(ListString &list) {
	return list.first->next == nullptr;
}

String removeListString(ListString &list) {
	if (list.first->next != nullptr) {
		ListStringNode *temprorary = list.first->next;
		String line = temprorary->line;
		list.first->next = list.first->next->next;
		delete temprorary;
		return line;
	}
	return list.first->line;
}

void clearListString(ListString &list) {
	String removeString = removeListString(list);
	while (list.first->next != nullptr) {
		clearString(removeString);
		removeString = removeListString(list);
	}
}

void printListString(ListString &list, FILE *output) {
	ListStringNode *current = list.first->next;
	while (current != nullptr) {
		fprintf(output, "How many includes - %d, word - ", current->number);
		printString(current->line, output);
		fprintf(output, "\n");
		current = current->next;
	}
}







