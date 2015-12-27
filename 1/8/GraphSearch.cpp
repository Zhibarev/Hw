#include <cstdio>
#include "queue.h"

using namespace std;

void bfsRecursion(int current, int size, int *colour, int whichColour, int *order, int whenVisit, int **graph, Queue bypass) {
	order[current] = whenVisit;
	for (int i = 0; i < size; i++)
		if (graph[current][i] == 1 && colour[i] == 0) {
			colour[i] = whichColour;
			add(i, bypass);
		}
	if (!isEmpty(bypass))
		bfsRecursion(remove(bypass), size, colour, whichColour, order, whenVisit + 1, graph, bypass);
}

void bfs(int first, int size, int *colour, int whichColour, int *order, int **graph) {
	bool nullColour = (colour == nullptr);
	if (nullColour) {
		colour = new int[size];
		for (int i = 0; i < size; i++)
			colour[i] = 0;
	}
	bool nullOrder = (order == nullptr);
	if (nullOrder)
		order = new int[size];
	for (int i = 0; i < size; i++)
			order[i] = 0;
	colour[first] = whichColour;
	Queue bypass = createQueue();
	bfsRecursion(first, size, colour, whichColour, order, 1, graph, bypass);
	if (nullOrder)
		delete []order;
	if (nullColour)
		delete []colour;
}