#pragma once

struct TreeListNode
{
	Tree tree;
	TreeListNode* next;
};

struct TreeList
{
	TreeListNode* first;
};

TreeList createTreeList();

Tree firstNode(TreeList &list);

void clearTreeList(TreeList &list);

void addTreeList(Tree &tree, TreeList &list);

Tree removeTreeList(TreeList &list);

bool isMoreOneNode(TreeList list);