#include <cstdio>
#include "Huffman.h"

using namespace std;

int main() {
	FILE *input = fopen("code.txt", "r");
	FILE *output = fopen("result.txt", "w");
	huffmanDecoding(input, output);
	fclose(input);
	fclose(output);
	return 0;
}