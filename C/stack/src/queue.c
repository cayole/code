#include "../inc/queue.h"
Queue* InitQueue(size_t size)
{
	if (size < 1) {
		return NULL;
	}
	if (size > MAX_SIZE) {
		size = MAX_SIZE;
	}

	Queue* queue = (Queue*) malloc(sizeof(Queue));
	if (!queue) {
		return NULL;
	}
	queue->data = (float*) malloc(sizeof(float) * size);
	if (!queue->data) {
		free(queue);
		return NULL;
	}
	queue->front = queue->rear = queue->count = 0;
	queue->size								  = size;
	return queue;
}
bool IfQueueFull(const Queue* queue) { return ((queue->rear + 1) % (queue->size) == queue->front); }
bool IfQueueEmpty(const Queue* queue) { return (queue->front == queue->rear); }

bool DeQueue(Queue* queue, float* data)
{
	if (IfQueueEmpty(queue)) {
		return false;
	}
	*data		  = queue->data[queue->front++];
	queue->front %= queue->size;
	return true;
}

bool EnQueue(Queue* queue, float data)
{
	if (IfQueueFull(queue)) {
		return false;
	}
	queue->data[queue->rear++]	= data;
	queue->rear				   %= queue->size;
	queue->count++;
	return true;
}

void ClearQueue(Queue* queue) { queue->rear = queue->front = 0; }

bool DeleteQueue(Queue* queue)
{
	if (!queue)
		return false;
	free(queue->data);
	queue->data = NULL;
	free(queue);
	queue->data;
	return true;
}