#include <cstdio>
#include <cstring>
#include "HuffmanTree.h"

using namespace std;

TreeNode* createTreeNode(int value, int frequency, TreeNode *leftChild, TreeNode *rightChild) {
	TreeNode* newNode = new TreeNode{value, frequency, leftChild, rightChild};
	return newNode;
}

Tree createTree(int value, int frequency) {
	TreeNode *guardian = createTreeNode(value, frequency, nullptr, nullptr);
	Tree newTree = {guardian};
	return newTree;
}

int frequency(Tree tree) {
	return tree.root->frequency;
}

Tree uniteTree(Tree &TreeFirst, Tree &TreeSecond) {
	Tree UnitedTree = {createTreeNode(0, frequency(TreeFirst) + frequency(TreeSecond), TreeFirst.root, TreeSecond.root)};
	return UnitedTree;
}

bool isDigit(char symbol) {
	return (symbol >= '0' && symbol <= '9');
}

void readRecursive(TreeNode *current, FILE *input) {
	char symbol = '0';
	fscanf(input, "%c", &symbol);
	if (symbol == '(') {
		int number = 0;
		fscanf(input, "%d", &number);
		current->left = createTreeNode(number, 0, nullptr, nullptr);
		readRecursive(current->left, input);
		fscanf(input, "%d", &number);
		current->right = createTreeNode(number, 0, nullptr, nullptr);
		readRecursive(current->right, input);
	}
}
			

Tree readTree(FILE *input) {
	int value = 0;
	fscanf(input, "%d", &value);
	Tree tree = createTree(value, 0);
	readRecursive(tree.root, input);
	return tree;
}

void printTreeRecursive(TreeNode *current, FILE *output) {
	if (current->left == nullptr)
		fprintf(output, "%d", current->value);
	else {
		fprintf(output, "%d(", current->value);
		printTreeRecursive(current->left, output);
		fprintf(output, " ");
		printTreeRecursive(current->right, output);
		fprintf(output, ")");
	}
}

void printTree(Tree tree, FILE *output) {
	printTreeRecursive(tree.root, output);
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

void convertRecursive(TreeNode *node, char **code, char *line, int current) {
	if (node->right == nullptr) {
		line[current] = '\0';
		strcpy(code[node->value], line);
	}
	else {
		line[current] = '1';
		convertRecursive(node->right, code, line, current + 1);
		line[current] = '0';
		convertRecursive(node->left, code, line, current + 1);
	}
}


char** convertToCode(Tree &huffmanTree) {
	char **code = new char*[256];
	for (int i = 0; i < 256; i++) {
		code[i] = new char[10];
		code[i][0] = '\0';
	}
	char *line = new char[10];
	if (huffmanTree.root->right == nullptr) {
		line[0] = '0';
		line[1] = '\0';
		strcpy(code[huffmanTree.root->value], line);
	}
	else
		convertRecursive(huffmanTree.root, code, line, 0);
	delete []line;
	return code;
}

char decodeRecursive(TreeNode *node, FILE *input) {
	if (node->left == nullptr)
		return node->value;
	char symbol = getc(input);
	if (symbol == '1')
		decodeRecursive(node->right, input);
	if (symbol == '0')
		decodeRecursive(node->left, input);
	if (symbol != '0' && symbol != '1')
		return EOF;
}

void decode(Tree &tree, FILE *input, FILE *output) {
	if (tree.root->value == 0) {
		char symbol = decodeRecursive(tree.root, input);
		while (symbol != EOF) {
			fprintf(output, "%c", symbol);
			symbol = decodeRecursive(tree.root, input);
		}	
	}
	else
		while (getc(input) != EOF)
			fprintf(output, "%c", tree.root->value);
}

















