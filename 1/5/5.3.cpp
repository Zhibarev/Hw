#include <iostream>
#include <fstream>

using namespace std;

int main() {
	FILE *text = fopen("programm.cpp", "r");
	char currentSymbol = ' ';
	char nextSymbol = ' ';
	while (currentSymbol != EOF) {
		while (currentSymbol != EOF && currentSymbol != '/' && currentSymbol != '"')
			currentSymbol = getc(text);	
		if (currentSymbol == '"') {
			currentSymbol = getc(text);
			while (currentSymbol != EOF && currentSymbol != '"')
				currentSymbol = getc(text);
			currentSymbol = getc(text);
		}
		if (currentSymbol == '/') {
			currentSymbol = getc(text);
			if (currentSymbol == '/') {
				printf("//");
				currentSymbol = getc(text);
				while (currentSymbol != EOF && currentSymbol != '\n') {
					printf("%c", currentSymbol);
					currentSymbol = getc(text);
				}
				printf("\n");
			}
			else {
				if (currentSymbol == '*') {
					currentSymbol = getc(text);
					nextSymbol = getc(text);
					while (nextSymbol != EOF && (currentSymbol != '*' || nextSymbol != '/')) {
						currentSymbol = nextSymbol;
						nextSymbol = getc(text);
					}
				}
			}
		}
	}
	fclose(text);
	return 0;
}