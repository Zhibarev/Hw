#pragma once

struct TreeNode
{
	int value;
	int height;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};

TreeNode* createTreeNode(int newValue);

Tree createTree();

int height(TreeNode *node);

int balanceFactor(TreeNode *node);

void updateHeight(TreeNode *node);

TreeNode* turnRight(TreeNode *root);

TreeNode* turnLeft(TreeNode *root);

TreeNode* balance(TreeNode *root);

TreeNode* addNote(int addValue, TreeNode *currentNode);

TreeNode* remove(int removeValue, TreeNode *currentNode);

bool isBelong(int searchingValue, Tree &tree);

void printInIncreasingOrder(TreeNode *current);

void printInDecreasingOrder(TreeNode *current);

void clearTree(Tree &tree);

void printTree(TreeNode *current);

void destroyTree(Tree &tree);