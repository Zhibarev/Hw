#include <cstdio>
#include "AVLTree.h"

int main() {
	int usersCommand = 1;
	int value = 0;
	Tree tree = createTree();
	printf("Help:\n0 - exit\n1 - add value to the tree\n2 - remove value from the tree\n3 - Is value belong to the tree\n4 - print elements in increasing order\n5 - print elements in decreasing order\n6 - print elements in 'tree' order\n");
	while (usersCommand != 0) {
		printf("Enter command\n");
		scanf("%d", &usersCommand);
		if (usersCommand == 1) {
			printf("Enter number\n");
			scanf("%d", &value);
			addNote(value, tree.root);
		}
		if (usersCommand == 2) {
			printf("Enter number\n");
			scanf("%d", &value);
			remove(value, tree.root->right);
		}
		if (usersCommand == 3) {
			printf("Enter number\n");
			scanf("%d", &value);
			if (isBelong(value, tree))
				printf("Yes\n");
			else
				printf("No\n");
		}
		if (usersCommand == 4) {
			printInIncreasingOrder(tree.root->right);
			printf("\n");
		}
		if (usersCommand == 5) {
			printInDecreasingOrder(tree.root->right);
			printf("\n");
		}
		if (usersCommand == 6) {
			printTree(tree.root->right);
			printf("\n");
		}
	}
	destroyTree(tree);
	return 0;
}