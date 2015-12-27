#include <cstdio>
#include "HuffmanTree.h"
#include "sortedTreeList.h"

using namespace std;

TreeList createTreeList() {
	TreeListNode *guardian = new TreeListNode{createTree(0, 0), nullptr};
	TreeList list = {guardian};
	return list;
}

Tree firstNode(TreeList &list) {
	return list.first->next != nullptr ? list.first->next->tree : list.first->tree;
}

void addTreeList(Tree &tree, TreeList &list) {
	TreeListNode *current = list.first;
	while ((current->next != nullptr) && (frequency(current->next->tree) <= frequency(tree)))
		current = current->next;
	TreeListNode *newElement = new TreeListNode{tree, current->next};
	current->next = newElement;
}

Tree removeTreeList(TreeList &list) {
	Tree treeToRemove = list.first->tree;
	if (list.first->next != nullptr) {
		TreeListNode *element = list.first->next;
		list.first->next = list.first->next->next;
		treeToRemove = element->tree;
		delete element;
	}
	return treeToRemove;
}

void clearTreeList(TreeList &list){
	TreeListNode *element = nullptr;
	while (list.first != nullptr) {
		element = list.first;
		list.first = list.first->next;
		delete element;
	}
}

bool isMoreOneNode(TreeList list) {
	return list.first->next == nullptr ? true: list.first->next->next == nullptr;
}