#include <cstdio>
#include "string.h"
#include "rabin.h"
#include <cstring>

using namespace std;

int main() {
	printf("Enter Substring and string\n");
	String sub = readString(stdin);
	String line = readString(stdin);
	int position = rabin(convertToChar(sub), convertToChar(line), 0);
	if (position == -1)
		printf("Not include\n");
	else {
		printf("Start of substring\n");
		while (position != -1) {
			printf("%d\n", position);
			position = rabin(convertToChar(sub), convertToChar(line), position + 1);
		}
	}
	clearString(sub);
	clearString(line);
	return 0;
}