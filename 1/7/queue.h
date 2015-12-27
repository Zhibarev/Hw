#pragma once

struct QueueNode{
	int number;
	QueueNode* next;
};

struct Queue{
	QueueNode* first;
	QueueNode* last;
};

Queue createQueue();

void add(int addNumber, Queue &queue);

int remove(Queue &queue);

void clearQueue(Queue &queue);

bool isEmpty(Queue queue);