#pragma once

struct String
{
	char *string;
	int length;
};

String createString(char *line);

int stringLength(const String &line);

String readString(FILE *input);

void addStringToString(const String &addString, String &line);

bool isEqual(const String &stringFirst, const String &stringSecond);

bool isEmpty(const String &line);

String clone(const String &line);

String expressSubstring(int begin, int end, const String &line);

char* convertToChar(const String &line);

void clearString(String &line);

void printString(const String &line, FILE *output);