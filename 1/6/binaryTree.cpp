#include <cstdio>
#include "binaryTree.h"

using namespace std;

TreeNode* createTreeNode(int newValue) {
	TreeNode *newTreeNode = new TreeNode{newValue, nullptr, nullptr};
}

Tree createTree() {
	Tree newTree = {nullptr};
	return newTree;
}

void addValue(int addValue, Tree &tree) {
	if (tree.root == nullptr)
		tree.root = createTreeNode(addValue);
	else {
		TreeNode *currentNode = tree.root;
		while (currentNode->value != addValue) {
			if (currentNode->value < addValue) {
				if (currentNode->right == nullptr)
					currentNode->right = createTreeNode(addValue);
				currentNode = currentNode->right;
			}
			else {
				if (currentNode->left == nullptr)
					currentNode->left = createTreeNode(addValue);
				currentNode = currentNode->left;
			}
		}
	}
}

TreeNode* removeRecursive(int removeValue, TreeNode *currentNode) {
	if (currentNode == nullptr)
		return nullptr;
	if (currentNode->value < removeValue)
		currentNode->right = removeRecursive(removeValue, currentNode->right);
	if (currentNode->value > removeValue)
		currentNode->left = removeRecursive(removeValue, currentNode->left);
	if (currentNode->value == removeValue) {
		if (currentNode->right == nullptr) {
			TreeNode *temporaryNode = currentNode->left;
			delete currentNode;
			return temporaryNode;
		}
		else
			if (currentNode->right != nullptr && currentNode->left == nullptr) {
				TreeNode *temporaryNode = currentNode->right;
				delete currentNode;
				return temporaryNode;
			}
			else {
				TreeNode *minRightLeftNode = currentNode->right;
				while (minRightLeftNode->left != nullptr)
					minRightLeftNode = minRightLeftNode->left;
				int temporary = minRightLeftNode->value;
				removeRecursive(temporary, currentNode);
				currentNode->value = temporary;
			}
	}
	return currentNode;
}

void remove(int removeValue, Tree &tree) {
	tree.root = removeRecursive(removeValue, tree.root);
}

bool search(int searchingValue, Tree &tree) {
	TreeNode *currentNode = tree.root;
	while (currentNode != nullptr && currentNode->value != searchingValue) {
		if (currentNode->value < searchingValue)
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left;
	}
	return (currentNode != nullptr);
}

void printInIncreasingOrder(TreeNode *current) {
	if (current != nullptr) {
		printInIncreasingOrder(current->left);
		printf("%d ", current->value);
		printInIncreasingOrder(current->right);
	}
}

void printInDecreasingOrder(TreeNode *current) {
	if (current != nullptr) {
		printInDecreasingOrder(current->right);
		printf("%d ", current->value);
		printInDecreasingOrder(current->left);
	}
}

void printTree(TreeNode *current) {
	if (current == nullptr)
		printf("nullptr");
	else {
		printf("%d (", current->value);
		printTree(current->left);
		printf(", ");
		printTree(current->right);
		printf(")");
	}
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