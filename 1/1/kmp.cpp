#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	char s1PlusS[1000000];
	char string[1000000];
	printf("Enter s1,s\n");
	scanf("%s %s", s1PlusS, string);
	int lengthS1 = strlen(s1PlusS);
	int lengthS = strlen(string);
	s1PlusS[lengthS1] = ' ';
	for (int i = lengthS1 + 1; i < (lengthS1 + 1 + lengthS); i++)
		s1PlusS[i] = string[i - lengthS1 - 1];
	int prefix[lengthS1 + lengthS + 1];
	int result = 0;
	int j = 0;
	prefix[0] = 0;
	for (int i = 1; i < (lengthS + lengthS1 + 1); i++) {
		j = i - 1;
		while ((s1PlusS[i] != s1PlusS[prefix[j]]) && (prefix[j] != 0))
			j = prefix[j] - 1;
		if (s1PlusS[i] == s1PlusS[prefix[j]])
			prefix[i] = prefix[j] + 1;
		else
			prefix[i] = 0;
		if (prefix[i] == lengthS1)
			result++;
	}
	printf("Result\n%d", result);
	return 0;
}