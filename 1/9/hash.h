#pragma once

#include "string.h"
#include "stringList.h"

struct HashTable {
	ListString *column;
	int size;
	int numberOfElements;
	int max;
};

HashTable createTable(int number);

void clearTable(HashTable &table);

bool searchStringHash(HashTable &table, String string);

void addToTable(HashTable &table, String string);

int hashTableSize(HashTable &table);

int hashTableNumber(HashTable &table);

int numberEmpties(HashTable &table);

void printMax(HashTable &table, FILE *output);

void printTable(HashTable &table, FILE *output);