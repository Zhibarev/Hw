#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int const lengthOfWord = 4;
	int word[lengthOfWord + 1];
	srand(time(NULL));
	int i = 1;
	int j = 0;
	word[0] = 10;
	while (i <= lengthOfWord) {
		j = 0;
		word[i] = rand() % 10;
		while ((j < i) && (word[j] != word[i]))
			j++;
		if ((j == i) || (word[j] != word[i]))
			i++;
	}
	int cow = 0;
	int bull = 0;
	int userWord = 0;
	int lastNumeric = 0;
	while ((bull != lengthOfWord) && (userWord != -1)) {
		bull = 0;
		cow = 0;
		printf("Enter four-digit number or -1 for end the game\n");
		scanf("%d", &userWord);
		if (userWord != -1) {
			for (int i = lengthOfWord; i >= 1; i--) {
				lastNumeric = (userWord - (userWord / 10) * 10);
				if (lastNumeric == word[i])
					bull++;
				for (int j = 1; j <= lengthOfWord; j++)
					if ((lastNumeric == word[j]) && (j != i))
						cow++;
				userWord = userWord / 10;
			}
		printf("bull = %d cow = %d\n", bull, cow);
		}
	}
	if (bull == lengthOfWord)
		printf("Victory");
	return 0;
}