#include <cstdio>
#include "treecalc.h"

using namespace std;

int main() {
	FILE *expression = fopen("expression.txt", "r");
	Tree actionTree = readTree(expression);
	fclose(expression);
	printf("Result: %d\nTree:\n", treeToResult(actionTree));
	printTree(actionTree);
	clearTree(actionTree);
	return 0;
}