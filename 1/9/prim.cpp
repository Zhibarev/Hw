#include <climits>
#include <cstdio>

using namespace std;

void newMin(int **graph, int size, int *min, int vertex) {
	for (int i = 1; i <= size; i++)
			if (min[i] == 0 && graph[i][vertex] != 0 && (min[vertex] == 0 || graph[i][vertex] < graph[min[vertex]][vertex]))
				min[vertex] = i;
	if (min[vertex] == 0)
		min[vertex] = -1;
}

int* prim(int **graph, int size) {
	int *tree = new int[size + 1];
	for (int i = 1; i <= size; i++)
		tree[i] = 0;
	int *min = new int[size + 1];
	for (int i = 1; i <= size; i++)
		min[i] = 0;
	int beginMin = 1;
	int endMin = -1;
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			if (graph[i][j] != 0 && (endMin == -1 || graph[i][j] < graph[beginMin][endMin])) {
				beginMin = i;
				endMin = j;
			}
	min[beginMin] = endMin;
	tree[beginMin] = beginMin;
	for (int k = 1; k < size; k++) {
		int minVisit = 0;
		for (int i = 1; i <= size; i++)
			if (min[i] != 0 && (minVisit == 0 || graph[i][min[i]] < graph[minVisit][min[minVisit]]))
				minVisit = i;
		tree[min[minVisit]] = minVisit;
		newMin(graph, size, min, min[minVisit]);
		min[minVisit] = 0;
		newMin(graph, size, min, minVisit);
	}
	delete []min;
	return tree;
}