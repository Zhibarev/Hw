#pragma once

#include "string.h"

struct ListStringNode
{
	int number;
	String line;
	ListStringNode* next;
};

struct ListString
{
	ListStringNode* first;
};

ListString createListString();

int lengthListString(ListString list);

bool isListEmpty(ListString &list);

void addListString(String &line, ListString &list);

String removeListString(ListString &list);

void clearListString(ListString &list);

void printListString(ListString &list, FILE *output);