#include <cstdio>
#include "Dijkstra.h"
#include <climits>
#include "stack.h"

using namespace std;

int main() {
	freopen("graph2.txt", "r", stdin);
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int **road = new int*[n];
	for (int i = 0; i < n; i++) {
		road[i] = new int[n];
		for (int j = 0; j < n; j++)
			road[i][j] = -1;
	}
	int townFirst = 0;
	int townSecond = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &townFirst, &townSecond);
		scanf("%d", &road[townFirst - 1][townSecond - 1]);
		road[townSecond - 1][townFirst - 1] = road[townFirst - 1][townSecond - 1];
	}
	int *way = new int[n];
	int *wayLength = new int[n];
	dijkstra(0, n, road, wayLength, way);
	int min = 0;
	Stack wayStack = createStack();
	printf("\n");
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = 0; j < n; j++)
			if (wayLength[min] > wayLength[j])
				min = j;
		printf("Town %d, Way length %d\nWay: ", min + 1, wayLength[min]);
		wayLength[min] = INT_MAX;
		while (min != 0) {
			push(min, wayStack);
			min = way[min];
		}
		push(min, wayStack);
		while (!isEmpty(wayStack))
			printf("%d ", pop(wayStack) + 1);
		printf("\n\n");
	}
	clearStack(wayStack);
	delete []way;
	delete []wayLength;
	for (int i = 0; i < n; i++)
		delete []road[i];
	delete []road;
	return 0;
}