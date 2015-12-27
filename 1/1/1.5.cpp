#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int main() {
	printf("Enter number of brackets\n");
	int n = 0;
	scanf("%d", &n);
	printf("Enter brackets\n");
	int difference = 0;
	int i = 1;
	char bracket = '(';
	while ((i <= n) && (difference >= 0)) {
		scanf("%c", &bracket);
		if ((bracket == '(') || (bracket == ')')) {
			if (bracket == '(')
				difference++;
			else
				difference--;
			i++;
		}
	}
	for (int j = i + 1; j <= n; j++)
		scanf("%c", &bracket);
	if (difference == 0)
		printf("Right");
	else
		printf("Wrong");
	return 0;
}
		
	