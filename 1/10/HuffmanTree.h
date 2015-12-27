#pragma once

struct TreeNode
{
	int value;
	int frequency;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};

Tree createTree(int value, int frequency);

int frequency(Tree tree);

Tree uniteTree(Tree &TreeFirst, Tree &TreeSecond);

void printTree(Tree tree, FILE *output);

Tree readTree(FILE *input);

void clearTree(Tree &tree);

char** convertToCode(Tree &huffmanTree);

void decode(Tree &tree, FILE *input, FILE *output);