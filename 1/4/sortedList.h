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

List createList();

void clearList(List &list);

void add(int value, List &list);

void remove(int value, List &list);

void printList(List list);