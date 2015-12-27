#pragma once

struct ListNode
{
	int number;
	ListNode* next;
};

struct List
{
	ListNode* first;
};

ListNode* creatListNode(int value, ListNode *nextList);

List createList(int value);

void clearList(List &list);

void add(int value, List &list);

ListNode* remove(List &list, ListNode *removeElement);

int last(List &list, int curse);