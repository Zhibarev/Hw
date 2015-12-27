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

Tree createTree();

void addValue(int addValue, Tree &tree);

void remove(int removeValue, Tree &tree);

bool search(int searchingValue, Tree &tree);

void printInIncreasingOrder(TreeNode *current);

void printInDecreasingOrder(TreeNode *current);

void clearTree(Tree &tree);

void printTree(TreeNode *current);