#include <cstdio>
#include "list.h"
using namespace std;

List createList() {
	ListNode guardian = {0, nullptr};
	List list = {guardian};
	return list;
}

void add(int value, List &list) {
	ListNode *newElement = new ListNode{value, list.first->next};
	list.first->next = newElement;
}

bool isEmpty(List &list) {
	return list.first->next == nullptr;
}

int remove(List &list) {
	int value = 0;
	if (list.first->next != nullptr) {
		value = list.first->next->number;
		ListNode *temprorary = list.first->next;
		list.first->next = list.first->next->next;
		delete temprorary;
	}
	return value;
}

void clearList(List &list) {
	while (list.first->next != nullptr)
		remove(list);
}
