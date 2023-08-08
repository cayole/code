#pragma once

#include "head.h"

#define MAX_SIZE 25
typedef struct Queue {
	float* data;
	size_t front, rear, size, count;
} Queue;

Queue* InitQueue(size_t size);
bool   DeQueue(Queue* queue, float* data);
bool   EnQueue(Queue* queue, float data);
bool   IfQueueFull(const Queue* queue);
bool   IfQueueEmpty(const Queue* queue);
void   ClearQueue(Queue* queue);
bool   DeleteQueue(Queue* queue);
