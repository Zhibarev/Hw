#include <cstdio>
#include "stringList.h"
#include <cstring>
using namespace std;

List createList() {
	ListNode *guardian = new ListNode{nullptr, nullptr, nullptr};
	List list = {guardian};
	return list;
}

void add(char addName[], char addnumber[], List &list) {
	ListNode *newElement = new ListNode{strcpy(new char[100], addnumber), strcpy(new char[100], addName), nullptr};
	newElement->next = list.first->next;
	list.first->next = newElement;
}

void clearList(List &list) {
	ListNode *element = nullptr;
	while (list.first->next != nullptr) {
		element = list.first->next;
		list.first->next = list.first->next->next;
		delete []element->number;
		delete []element->name;
		delete element;
	}
}

char* findNumber(char entredName[], List &list) {
	ListNode *current = list.first->next;
	while (current != nullptr && strcmp(entredName, current->name) != 0)
		current = current->next;
	if (current != nullptr)
		return current->number;
	return nullptr;
}

char* findName(char phoneNumber[], List &list) {
	ListNode *current = list.first->next;
	while (current != nullptr && strcmp(phoneNumber, current->number) != 0)
		current = current->next;
	if (current != nullptr)
		return &current->name[0];
	return nullptr;
}

void printList(List list, FILE *out) {
	ListNode *current = list.first->next;
	while(current != nullptr) {
		fprintf(out, "\n%s %s", current->name, current->number);
		current = current->next;
	}
}







