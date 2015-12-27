#include <cstdio>
#include "cstring"
#include "HuffmanTree.h"
#include "SortedTreeList.h"
#include "Huffman.h"
using namespace std;

void huffmanCoding(FILE *input, FILE *output) {
	int symbolFrequence[256];
	for (int i = 0; i < 256; i++)
		symbolFrequence[i] = 0;
	char symbol = getc(input);
	while (symbol != EOF) {
		symbolFrequence[symbol]++;
		symbol = getc(input);
	}
	TreeList sortedFrequence = createTreeList();
	Tree newTree;
	for (int i = 0; i < 256; i++)
		if (symbolFrequence[i] != 0) {
			newTree = createTree(i, symbolFrequence[i]);
			addTreeList(newTree, sortedFrequence);
		}
	Tree treeToUniteFirst;
	Tree treeToUniteSecond;
	Tree unitedTree;
	while (!isMoreOneNode(sortedFrequence)) {
		treeToUniteFirst = removeTreeList(sortedFrequence);
		treeToUniteSecond = removeTreeList(sortedFrequence);
		unitedTree = uniteTree(treeToUniteFirst, treeToUniteSecond);
		addTreeList(unitedTree, sortedFrequence);
	}
	Tree resultTree = removeTreeList(sortedFrequence);
	char **code = convertToCode(resultTree);
	fseek(input, 0, SEEK_SET);
	printTree(resultTree, output);
	fprintf(output, "\n");
	symbol = getc(input);
	while (symbol != EOF) {
		fprintf(output, "%s", code[symbol]);
		symbol = getc(input);
	}
	clearTree(resultTree);
	for (int i = 0; i < 256; i++)
		delete []code[i];
	delete []code;
}

void huffmanDecoding(FILE *input, FILE *output) {
	Tree tree = readTree(input);
	getc(input);
	decode(tree, input, output);
}