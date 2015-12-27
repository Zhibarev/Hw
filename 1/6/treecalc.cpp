#include <cstdio>
#include "treecalc.h"

using namespace std;

TreeNode* createTreeNode(int newValue) {
	TreeNode *newTreeNode = new TreeNode{newValue, nullptr, nullptr};
}

Tree createTree() {
	Tree newTree = {nullptr};
	return newTree;
}

int getExpresion(FILE *expression) {
	char symbol = getc(expression);
	if (symbol > '9' || symbol < '0') {
		getc(expression);
		return symbol;
	}
	int number = 0;
	while (symbol <= '9' && symbol >= '0') {
		number = number * 10 + (symbol - '0');
		symbol = getc(expression);
	}
	return number;
}

void readRecursive(TreeNode *current, FILE *expression) {
	char symbol = getc(expression);
	int number = 0;
	if (symbol == '(') {
		current->right = createTreeNode(getExpresion(expression));
		readRecursive(current->right, expression);
	}
	else {
		ungetc(symbol, expression);
		current->right = createTreeNode(getExpresion(expression));
	}
	symbol = getc(expression);
	if (symbol == '(') {
		current->left = createTreeNode(getExpresion(expression));
		readRecursive(current->left, expression);
	}
	else
		if (symbol != EOF) {
			ungetc(symbol, expression);
			current->left = createTreeNode(getExpresion(expression));
			getc(expression);
		}
}
			

Tree readTree(FILE *expression) {
	Tree actionTree = createTree();
	actionTree.root = createTreeNode(-1);
	readRecursive(actionTree.root, expression);
	return actionTree;
}

int calculate(int number1, int number2, char action) {
	if (action == '+')
		return number1 + number2;
	if (action == '-')
		return number1 - number2;
	if (action == '*')
		return number1 * number2;
	return number1 / number2;
}

int count(TreeNode *current) {
	if (current->left == nullptr)
		return current->value;
	return calculate(count(current->right), count(current->left), current->value);
}

int treeToResult(Tree &tree) {
	return count(tree.root->right);
}

void printRecursive(TreeNode *current) {
	if (current == nullptr)
		printf("nullptr");
	else {
		if (current->left == nullptr)
			printf("%d (", current->value);
		else
			printf("%c (", current->value);
		printRecursive(current->left);
		printf(", ");
		printRecursive(current->right);
		printf(")");
	}
}

void printTree(Tree &tree) {
	printRecursive(tree.root->right);
}

void clearTreeRecursive(TreeNode *current) {
	if (current->right != nullptr)
		clearTreeRecursive(current->right);
	if (current->left != nullptr)
		clearTreeRecursive(current->left);
	delete current;
}

void clearTree(Tree &tree) {
	if (tree.root != nullptr)
		clearTreeRecursive(tree.root);
}




	