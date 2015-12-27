#include <cstdio>
#include <cstring>
#include "queue.h"
using namespace std;

Queue createQueue() {
	Queue newQueue = {nullptr, nullptr};
	return newQueue;
}

void add(int addNumber, Queue &queue) {
	QueueNode* newElement = new QueueNode;
	newElement->number = addNumber;
	newElement->next = queue.first;
	queue.first = newElement;
	if (queue.last == nullptr)
		queue.last = newElement;
}

int remove(Queue &queue) {
	int value = 0;
	if (queue.first != nullptr) {
		value = queue.last->number;
		if (queue.first == queue.last) {
			delete queue.first;
			queue.first = nullptr;
			queue.last = nullptr;
		}
		else {
			QueueNode* current = queue.first;
			while (current->next != queue.last)
				current = current->next;
			delete queue.last;
			current->next = nullptr;
			queue.last = current;
		}
	}
	return value;
}

void clearQueue(Queue &queue) {
	while (queue.last != nullptr)
		remove(queue);
}

bool isEmpty(Queue queue) {
	return (queue.first == nullptr);
}