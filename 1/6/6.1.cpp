#include <cstdio>
#include "binaryTree.h"

int main() {
	int usersCommand = 1;
	int value = 0;
	Tree tree = createTree();
	printf("Help:\n0 - exit\n1 - add value to the tree\n2 - remove value from the tree\n3 - Is value belong to the tree\n4 - print elements in increasing order\n5 - print elements in decreasing order\n6 - print elements in 'tree' order\n");
	enum {exit, add, removeValue, searchValue, printIncrease, printDecrease, print};
	while (usersCommand != exit) {
		printf("Enter command\n");
		scanf("%d", &usersCommand);
		switch (usersCommand) {
			case add:
				printf("Enter number\n");
				scanf("%d", &value);
				addValue(value, tree);
			break;
			case removeValue:
				printf("Enter number\n");
				scanf("%d", &value);
				remove(value, tree);
			break;
			case searchValue:
				printf("Enter number\n");
				scanf("%d", &value);
				if (search(value, tree))
					printf("Yes\n");
				else
					printf("No\n");
			break;
			case printIncrease:
				printInIncreasingOrder(tree.root);
				printf("\n");
			break;
			case printDecrease:
				printInDecreasingOrder(tree.root);
				printf("\n");
			break;
			case print:
				printTree(tree.root);
				printf("\n");
			break;
		}
	}
	clearTree(tree);
	return 0;
}