#include <cstdio>

using namespace std;

void dijkstraRecursive(int current, int size, int **road, int *wayLength, bool *isVisit, int *way){
	isVisit[current] = true;
	for (int i = 0; i < size; i++)
		if (!isVisit[i] && road[current][i] != -1)
			if (wayLength[i] == -1 || (wayLength[i] > wayLength[current] + road[current][i])) {
				wayLength[i] = wayLength[current] + road[current][i];
				way[i] = current;
			}
	int nextVertex = -1;
	for (int i = 0; i < size; i++)
		if (!isVisit[i] && wayLength[i] != -1)
			if (nextVertex == -1)
				nextVertex = i;
			else
				if (wayLength[i] < wayLength[nextVertex])
					nextVertex = i;
	if (nextVertex != -1)
		dijkstraRecursive(nextVertex, size, road, wayLength, isVisit, way);
}

void dijkstra(int first, int size, int **road, int *wayLength, int *way) {
	bool *isVisit = new bool[size];
	for (int i = 0; i < size; i++) {
		wayLength[i] = -1;
		isVisit[i] = false;
	}
	wayLength[first] = 0;
	way[first] = 0;
	dijkstraRecursive(first, size, road, wayLength, isVisit, way);
	delete []isVisit;
}