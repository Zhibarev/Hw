#include <cstdio>
#include "Huffman.h"

using namespace std;

int main() {
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("code.txt", "w");
	huffmanCoding(input, output);
	fclose(input);
	fclose(output);
	return 0;
}