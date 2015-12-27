#include <cstdio>
#include <cstring>
#include "queue.h"
using namespace std;

Queue createQueue() {
	Queue newQueue = {nullptr, nullptr};
	return newQueue;
}

void add(int addNumber, Queue &queue) {
	QueueNode* newElement = new QueueNode{addNumber, nullptr};
	if (queue.last == nullptr)
		queue.first = newElement;
	else
		queue.last->next = newElement;
	queue.last = newElement;
}

int remove(Queue &queue) {
	int value = 0;
	if (queue.first != nullptr) {
		value = queue.first->number;
		if (queue.first == queue.last)
			queue.last = nullptr;
		QueueNode *temprorary = queue.first->next;
		delete queue.first;
		queue.first = temprorary;
	}
	return value;
}

void clearQueue(Queue &queue) {
	while (queue.first != nullptr)
		remove(queue);
}

bool isEmpty(Queue queue) {
	return (queue.first == nullptr);
}