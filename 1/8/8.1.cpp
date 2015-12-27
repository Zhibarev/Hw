#include <cstdio>
#include "GraphSearch.h"
#include "queue.h"

using namespace std;

int main() {
	printf("Enter first vertex and name of file (in file graph as array[size][size])\n");
	int first = 0;
	char fileName[100];
	scanf("%d %s", &first, fileName);
	FILE *file = fopen(fileName, "r");
	int size = 0;
	char symbol = ' ';
	while (symbol != EOF && symbol != '\n') {
		symbol = getc(file);
		if (symbol == '1' || symbol == '0')
		 size++;
	}
	fclose(file);
	file = fopen(fileName, "r");
	int **graph = new int*[size];
	for (int i = 0; i < size; i++)
		graph[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			fscanf(file, "%d", &graph[i][j]);
	fclose(file);
	int *order = new int[size];
	bfs(first, size, nullptr, 1, order, graph);
	for (int i = 0; i < size; i++)
		printf("vertex %d - letter %c\n", i, order[i] - 1 + 'a');
	delete []order;
	for (int i = 0; i < size; i++)
		delete []graph[i];
	delete []graph;
	return 0;
}