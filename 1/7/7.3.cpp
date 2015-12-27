#include <cstdio>
#include "string.h"
#include "hash.h"

using namespace std;

int main() {
	FILE *book = fopen("book.txt", "r");
	HashTable table = createTable(73);
	char symbol = getc(book);
	while (symbol != EOF) {
		while (symbol == ' ' || symbol == '\n' || symbol == '\r')
			symbol = getc(book);
		if (symbol != EOF) {
			ungetc(symbol, book);
			addToTable(table, readString(book));
			symbol = getc(book);
		}
	}
	fclose(book);
	FILE *output = fopen("output.txt", "w");
	printTable(table, output);
	fclose(output);
	printf("Number of words %d\nLoad factor %d\nNumber of empty lists %d\nMax length and list\n", hashTableNumber(table), hashTableNumber(table) / hashTableSize(table), numberEmpties(table));
	printMax(table, stdout);
	clearTable(table);
	return 0;
}