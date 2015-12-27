#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	printf("Enter string\n");
	char string[1000000];
	scanf("%s", &string);
	int i = 0;
	while ((i <= (strlen(string) / 2 - 1)) && (str[i] == str[strlen(string) - i - 1]))
		i++;
	if (i > (strlen(string) / 2 - 1))
		printf("YES");
	else
		printf("NO");
	return 0;
}
		
	