#include <cstdio>
#include <cstring>
#include "queue.h"
#include "string.h"

using namespace std;

String createString(char *line) {
	String string = {line , 0};
	if (line != nullptr)
		string.length = strlen(line);
	return string;
}

int stringLength(const String &line) {
	return line.length;
}

bool isEmpty(const String &line) {
	return (line.length == 0);
}

String readString(FILE *input) {
	Queue queue = createQueue();
	int readLength = 0;
	char symbol = '\n';
	while (symbol == '\n' || symbol == '\r' || symbol == ' ')
		symbol = getc(input);
	while (symbol != '\n' && symbol != '\r' && symbol != EOF && symbol != ' ') {
		add(symbol, queue);
		readLength++;
		symbol = getc(input);
	}
	String line = createString(nullptr);
	line.length = readLength;
	line.string = new char[line.length];
	for (int i = 0; i < line.length; i++)
		line.string[i] = remove(queue);
	return line;
}

void addStringToString(const String &addString, String &line) {
	char *temprorary = new char[line.length + addString.length];
	for (int i = 0; i < line.length; i++)
		temprorary[i] = line.string[i];
	for (int i = line.length; i < line.length + addString.length; i++)
		temprorary[i] = addString.string[i - line.length];
	if (!isEmpty(line))
		delete []line.string;
	line.length += addString.length;
	line.string = temprorary;
}

bool isEqual(const String &stringFirst, const String &stringSecond) {
	if (stringFirst.length != stringSecond.length)
		return false;
	for (int i = 0; i < stringFirst.length; i++)
		if (stringFirst.string[i] != stringSecond.string[i])
			return false;
	return true;
}

String clone(const String &line) {
	String stringClone = createString(nullptr);
	addStringToString(line, stringClone);
	return stringClone;
}

String expressSubstring(int begin, int end, const String &line) {
	String substring = createString(nullptr);
	substring.length = end - begin + 1;
	substring.string = new char[substring.length];
	for (int i = begin; i <= end; i++)
		substring.string[i - begin] = line.string[i];
	return substring;
}

char* convertToChar(const String &line) {
	return line.string;
}

void clearString(String &line) {
	if (!isEmpty(line))
		delete []line.string;
	line.length = 0;
}

void printString(const String &line, FILE *output) {
	for (int i = 0; i < line.length; i++)
		fprintf(output, "%c", line.string[i]);
}












