#include <cstdio>
#include "sortedList.h"
using namespace std;

ListNode* creatListNode(int value, ListNode *nextList){
	ListNode *newNode = new ListNode;
	newNode->number = value;
	newNode->next = nextList;
	return newNode;
}

List createList(){
	List list = {creatListNode(0, NULL)};
	return list;
}

void add(int value, List &list){
	ListNode *current = list.first;
	while ((current->next != NULL) && (current->next->number <= value))
		current = current->next;
	ListNode *newElement = creatListNode(value, current->next);
	current->next = newElement;
}

void remove(int value, List &list){
	ListNode *current = list.first;
	while (current->next != NULL){
		if (current->next->number == value){
			ListNode *element = current->next;
			current->next = current->next->next;
			delete element;
		}
		else
			current = current->next;
	}
}

void clearList(List &list){
	ListNode *element = NULL;
	while (list.first != NULL) {
		element = list.first;
		list.first = list.first->next;
		delete element;
	}
}

void printList(List list){
	ListNode *current = list.first->next;
	if (current == NULL)
		printf("Empty list\n");
	while (current != NULL) {
		printf("%d ", current->number);
		current = current->next;
	}	
}
	