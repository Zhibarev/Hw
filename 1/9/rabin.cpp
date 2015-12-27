#include <cstring>
#include <cstdio>

using namespace std;

int const prime = 11;

int const maxLength = 15;

long long degree[maxLength];

long long hash(char *line, int begin, int end) {
	int length = strlen(line);
	int result = 0;
	for (int i = 0; i < end - begin; i++)
		result += line[end - 1 - i] * degree[i];
	return result;
}

int rabin(char *sub, char *line, int first) {
	degree[0] = 1;
	for (int i = 1; i < maxLength; i++)
		degree[i] = degree[i - 1] * prime;
	int subLength = strlen(sub);
	int lineLength = strlen(line);
	int hashSub = hash(sub, 0, subLength);
	int hashLine = hash(line, first, subLength + first);
	int j = 0;
	for (int i = first; i <= lineLength - subLength; i++) {
		if (hashSub == hashLine) {
			j = 0;
			while (j != subLength && sub[j] == line[i + j])
				j++;
			if (j == subLength)
				return i;
		}
		if (i != lineLength - subLength)
			hashLine = (hashLine - degree[subLength - 1] * line[i]) * prime + line[i + subLength];
	}
	return -1;
}