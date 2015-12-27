#include <cstdio>
#include "GraphSearch.h"
#include "queue.h"

using namespace std;

int main() {
	printf("Enter size and graph (graph as array[size][size])\n");
	int size = 0;
	scanf("%d", &size);
	int **graph = new int*[size];
	for (int i = 0; i < size; i++)
		graph[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			scanf("%d", &graph[i][j]);
	int *component = new int[size];
	for (int i = 0; i < size; i++)
		component[i] = 0;
	int whichComponent = 1;
	for (int i = 0; i < size; i++) {
		if (component[i] == 0) {
			bfs(i, size, component, whichComponent, nullptr, graph);
			whichComponent++;
		}
	}
	for (int i = 0; i < size; i++)
		printf("Vertex %d - Component %d\n", i, component[i]); 
	delete []component;
	for (int i = 0; i < size; i++)
		delete []graph[i];
	delete []graph;
	return 0;
}