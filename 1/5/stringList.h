#pragma once

struct ListNode
{
	char* number;
	char* name;
	ListNode* next;
};

struct List
{
	ListNode* first;
};

List createList();

void clearList(List &list);

void add(char addnumber[], char addName[], List &list);

char* findNumber(char entredName[], List &list);

char* findName(char phoneNumber[], List &list);

void printList(List list, FILE *out);