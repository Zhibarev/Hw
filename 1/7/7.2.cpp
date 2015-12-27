#include <cstdio>
#include "list.h"
#include "string.h"

using namespace std;

String actionsWithString(String &string) {
	enum {exit, read, deleteString, length, print, emptyCheck, help};
	int command = 1;
	while (command != exit) {
		printf("Enter command, 6 for help\n");
		scanf("%d", &command);
		switch (command) {
			case exit:
				return string;
			break;
			case read:
				printf("Enter string\n");
				string = readString();
			break;
			case deleteString:
				clearString(string);
			break;
			case length:
				printf("Length = %d\n", stringLength(string));
			break;
			case print:
				printString(string);
				printf("\n");
			break;
			case emptyCheck:
				if (isEmpty(string))
					printf("Yes\n");
				else
					printf("No\n");		
			break;
			case help:
				printf("Help:\n0 exit\n1 read string\n2 delete\n3 print length\n4 print string\n5 check is string empty\n6 help\n");
			break;
		}
	}
}

void interface(String &stringFirst, String &stringSecond) {
	enum {exit, first, second, copy, addFirstToSecond, substring, equalCheck, help};
	int begin = 0;
	int end = 0;
	int command = 1;
	while (command != exit) {
		printf("Enter command, 7 for help\n");
		scanf("%d", &command);
		switch (command) {
			case exit:
				clearString(stringFirst);
				clearString(stringSecond);
			break;
			case first:
				stringFirst = actionsWithString(stringFirst);
			break;
			case second:
				stringSecond = actionsWithString(stringSecond);
			break;
			case copy:
				stringSecond = clone(stringFirst);
			break;
			case addFirstToSecond:
				addStringToString(stringSecond, stringFirst);
			break;
			case substring:
				printf("Enter begin and end\n");
				scanf("%d %d", &begin, &end);
				stringSecond = expressSubstring(begin, end, stringFirst);
			break;
			case equalCheck:
				if (isEqual(stringFirst, stringSecond))
					printf("Yes\n");
				else
					printf("No\n");
			break;
			case help:
				printf("Help:\n0 exit\n1 action with first string\n2 action with second string\n3 copy first one to second\n4 add second string to first\n5 extract substring from first to second\n6 check is first equal to second\n7 help\n\n");
			break;
		}
	}
}

int main() {
	int usersCommand = 1;
	char symbol = '1';
	int whichString = 0;
	int begin = 0;
	int end = 0;
	char *string = nullptr;
	int stringLength = 0;
	String stringFirst = createString(nullptr);
	String stringSecond = createString(nullptr);
	interface(stringFirst, stringSecond);
	return 0;
}