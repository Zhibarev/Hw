#include <cstdio>
#include "clist.h"
using namespace std;

ListNode* creatListNode(int value, ListNode *nextList){
	ListNode *newNode = new ListNode;
	newNode->number = value;
	newNode->next = nextList;
	return newNode;
}

List createList(int value){
	List list = {creatListNode(value, NULL)};
	list.first->next = list.first;
	return list;
}

void add(int value, List &list){
	ListNode *newElement = creatListNode(value, list.first->next);
	list.first->next = newElement;
	list.first = newElement;
}

ListNode* remove(List &list, ListNode *removeElement){
	ListNode *current = removeElement;
	while (current->next != removeElement)
		current = current->next;
	current->next = removeElement->next;
	delete(removeElement);
	return current->next;
}

void clearList(List &list){
	ListNode *element = NULL;
	while (list.first->next != list.first) {
		element = list.first;
		list.first = list.first->next;
		delete element;
	}
	element = list.first;
	list.first = NULL;
	delete element;
}

int last(List &list, int curse){
	int i = 1;
	ListNode *current = list.first->next;
	while (current->next != current) {
		if (i != curse) {
			i++;
			current = current->next;
		}
		else {
			current = remove(list, current);
			i = 1;
		}
	}
	return current->number;
}