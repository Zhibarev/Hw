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

List createList();

void add(int value, List &list);

bool isEmpty(List &list);

int remove(List &list);

void clearList(List &list);