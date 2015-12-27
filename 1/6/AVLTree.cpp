#include <cstdio>
#include "AVLTree.h"

using namespace std;

int const guardValue = -1;

TreeNode* createTreeNode(int newValue) {
	TreeNode *newTreeNode = new TreeNode{newValue, 0, NULL, NULL};
}

Tree createTree() {
	TreeNode *guardian = createTreeNode(guardValue);
	Tree newTree = {guardian};
	return newTree;
}

int height(TreeNode *node) {
	return node ? node->height : 0;
}

int balanceFactor(TreeNode *node) {
	return node ? height(node->right) - height(node->left) : 0;
}

void updateHeight(TreeNode *node) {
	node->height = (height(node->right) > height(node->left) ? height(node->right) : height(node->left)) + 1;
}

TreeNode* turnRight(TreeNode *root) {
	TreeNode *newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;
	updateHeight(root);
	updateHeight(newRoot);
	return newRoot;
}

TreeNode* turnLeft(TreeNode *root) {
	TreeNode *newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;
	updateHeight(root);
	updateHeight(newRoot);
	return newRoot;
}

TreeNode* balance(TreeNode *root) {
	updateHeight(root);
	if (balanceFactor(root) < 2 && balanceFactor(root) > -2)
		return root;
	if (balanceFactor(root) == 2) {
		if (balanceFactor(root->right) < 0)
			root->right = turnRight(root->right);
		return turnLeft(root);
	}
	if (balanceFactor(root->left) > 0)
		root->left = turnLeft(root->left);
	return turnRight(root);
}

TreeNode* addNote(int addValue, TreeNode *currentNode) {
	if (currentNode->value < addValue) {
		if (currentNode->right == NULL)
			currentNode->right = createTreeNode(addValue);
		currentNode->right = addNote(addValue, currentNode->right);
	}
	if (currentNode->value > addValue) {
		if (currentNode->left == NULL)
			currentNode->left = createTreeNode(addValue);
		currentNode->left = addNote(addValue, currentNode->left);
	}
	return currentNode->value != guardValue ? balance(currentNode) : NULL;
}

TreeNode* remove(int removeValue, TreeNode *currentNode) {
	if (currentNode == NULL)
		return NULL;
	if (currentNode->value < removeValue)
		currentNode->right = remove(removeValue, currentNode->right);
	if (currentNode->value > removeValue)
		currentNode->left = remove(removeValue, currentNode->left);
	if (currentNode->value == removeValue) {
		if (currentNode->right == NULL) {
			TreeNode *temporaryNode = currentNode->left;
			delete currentNode;
			return temporaryNode;
		}
		else
			if (currentNode->right != NULL && currentNode->left == NULL) {
				TreeNode *temporaryNode = currentNode->right;
				delete currentNode;
				return temporaryNode;
			}
			else {
				TreeNode *minRightLeftNode = currentNode->right;
				while (minRightLeftNode->left != NULL)
					minRightLeftNode = minRightLeftNode->left;
				int temporary = minRightLeftNode->value;
				remove(temporary, currentNode);
				currentNode->value = temporary;
			}
	}
	balance(currentNode);
	return currentNode;
}

bool isBelong(int searchingValue, Tree &tree) {
	TreeNode *currentNode = tree.root;
	while (currentNode != NULL && currentNode->value != searchingValue) {
		if (currentNode->value < searchingValue)
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left;
	}
	return (currentNode != NULL);
}

void printInIncreasingOrder(TreeNode *current) {
	if (current != NULL) {
		printInIncreasingOrder(current->left);
		printf("%d ", current->value);
		printInIncreasingOrder(current->right);
	}
}

void printInDecreasingOrder(TreeNode *current) {
	if (current != NULL) {
		printInDecreasingOrder(current->right);
		printf("%d ", current->value);
		printInDecreasingOrder(current->left);
	}
}

void printTree(TreeNode *current) {
	if (current == NULL)
		printf("NULL");
	else {
		printf("%d (", current->value);
		printTree(current->left);
		printf(", ");
		printTree(current->right);
		printf(")");
	}
}

void clearTree(TreeNode *current) {
	if (current->right != NULL)
		clearTree(current->right);
	if (current->left != NULL)
		clearTree(current->left);
	delete current;
}

void destroyTree(Tree &tree) {
	if (tree.root->right != NULL)
		clearTree(tree.root->right);
	delete tree.root;
}