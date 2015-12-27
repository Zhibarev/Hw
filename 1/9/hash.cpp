#include <cstdio>
#include "hash.h"

using namespace std;

int hashFunction(String string, int size) {
	int hashValue = 0;
	char *line = convertToChar(string);
	int length = stringLength(string);
	for (int i = 0; i < length; i++)
		if (line[i] >= 0)
			hashValue = (hashValue +  (i + 1) * line[i]) % size;
	return hashValue;
}

bool isPrime(int number) {
	for (int i = 2; i * i <= number; i++)
		if (number % i == 0)
			return false;
	return true;
}

int nextPrime(int prime) {
	int i = prime + 1;
	while (!isPrime(i))
		i = i + 1;
	return i;
}

HashTable createTable(int HashNumber) {
	int size = nextPrime(HashNumber - 1);
	ListString *column = new ListString[size];
	for (int i = 0; i < size; i++)
		column[i] = createListString();
	HashTable table = {column, size, 0, 0};
	return table;
}

void rebuildTable(HashTable &table) {
	int newSize = nextPrime(table.size * 2);
	HashTable newTable = createTable(newSize);
	newTable.numberOfElements = table.numberOfElements;
	String line = createString(nullptr);
	for (int i = 0; i < table.size; i++)
		while (!isListEmpty(table.column[i])) {			
			line = removeListString(table.column[i]);
			addListString(line, newTable.column[hashFunction(line, newSize)]);
		}
	clearTable(table);
	table = newTable;
}

bool searchStringHash(HashTable &table, String string) {
	return (searchString(string, table.column[hashFunction(string, table.size)]));
}

void clearTable(HashTable &table) {
	for (int i = 0; i < table.size; i++)
		if (!isListEmpty(table.column[i]))
			clearListString(table.column[i]);
	delete []table.column;
}

void addToTable(HashTable &table, String string) {
	int hash = hashFunction(string, table.size);
	addListString(string, table.column[hash]);
	table.numberOfElements++;
	if (lengthListString(table.column[hash]) > lengthListString(table.column[table.max]))
		table.max = hash;
	if (table.numberOfElements / table.size > 10)
		rebuildTable(table);
}

int hashTableSize(HashTable &table) {
	return table.size;
}

int hashTableNumber(HashTable &table) {
	return table.numberOfElements;
}

void printMax(HashTable &table, FILE *output) {
	printf("%d\n", lengthListString(table.column[table.max]));
	printListString(table.column[table.max], output);
}

void printTable(HashTable &table, FILE *output) {
	for (int i = 0; i < table.size; i++)
		printListString(table.column[i], output);
}

int numberEmpties(HashTable &table) {
	int result = 0;
	for (int i = 0; i < table.size; i++)
		if (isListEmpty(table.column[i]))
			result++;
	return result;
}