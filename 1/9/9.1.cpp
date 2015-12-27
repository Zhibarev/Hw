#include <cstdio>
#include "hash.h"

using namespace std;

int main() {
	FILE *first = fopen("first.txt", "r");
	HashTable table = createTable(73);
	char symbol = getc(first);
	while (symbol != EOF) {
		while (symbol == ' ' || symbol == '\n' || symbol == '\r')
			symbol = getc(first);
		if (symbol != EOF) {
			ungetc(symbol, first);
			addToTable(table, readString(first));
			symbol = getc(first);
		}
	}
	fclose(first);
	FILE *output = fopen("output.txt", "w");
	FILE *second = fopen("second.txt", "r");
	String line;
	symbol = getc(second);
	while (symbol != EOF) {
		while (symbol == ' ' || symbol == '\n' || symbol == '\r')
			symbol = getc(second);
		if (symbol != EOF) {
			ungetc(symbol, second);
			line = readString(second);
			if (searchStringHash(table, line)) {
				printString(line, output);
				fprintf(output, "\n");
			}
			symbol = getc(second);
		}
	}
	fclose(second);
	fclose(output);
	clearTable(table);
	return 0;
}