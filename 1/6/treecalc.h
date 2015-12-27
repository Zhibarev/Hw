#pragma once

struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};

Tree readTree(FILE *expression);

int treeToResult(Tree &tree);

void printTree(Tree &tree);

void clearTree(Tree &tree);