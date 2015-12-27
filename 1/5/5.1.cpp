#include <iostream>
#include <fstream>

using namespace std;

bool ifLetter(char element) {
	return (((element >= 'A') && (element <= 'Z')) || ((element >= 'a') && (element <= 'z')));
}

char whichLetter(char letter) {
	return (letter <= 'Z') ? letter - 'A' : letter - 'a';
}

int main() {
	FILE *text = fopen("file.txt", "r");
	int const numberOfLetters = 26;
	bool IsLetterInclude[numberOfLetters];
	for (int i = 0; i < numberOfLetters; i++)
		IsLetterInclude[i] = false;
	char currentSymbol = getc(text);
	while (currentSymbol != EOF) {
		while (currentSymbol != EOF && !ifLetter(currentSymbol))
			currentSymbol = getc(text);
		while (currentSymbol != EOF && ifLetter(currentSymbol)) {
			if (!IsLetterInclude[whichLetter(currentSymbol)]) {
				IsLetterInclude[whichLetter(currentSymbol)] = true;
				printf("%c", currentSymbol);
			}
			currentSymbol = getc(text);	
		}
		printf(" ");
		for (int i = 0; i < numberOfLetters; i++)
			IsLetterInclude[i] = false;
	}
	fclose(text);
	return 0;
}