#include "../inc/queue.h"

/// @brief 创建并初始化队列
/// @param size
/// @return 空队列
Queue* InitQueue(size_t size)
{
	if (size < 1) {
		return NULL;
	}
	if (size > MAX_Queue_SIZE) {
		size = MAX_Queue_SIZE;
	}

	Queue* queue = (Queue*) malloc(sizeof(Queue));	  // 创建队列
	if (!queue) {
		return NULL;
	}
	queue->data = (float*) malloc(sizeof(float) * size);
	if (!queue->data) {
		free(queue);
		return NULL;
	}
	queue->front = queue->rear = queue->count = 0;		 // 初始化
	queue->size								  = size;	 // 初始化
	return queue;
}

/// @brief 判段队列是否为满
/// @param queue
/// @return bool
bool IfQueueFull(const Queue* queue) { return (queue->count == queue->size); }

/// @brief 判断队列是否为空
/// @param queue
/// @return bool
bool IfQueueEmpty(const Queue* queue) { return (queue->count == 0); }

/// @brief 出队
/// @param queue
/// @param data
/// @return 是否成功
bool DeQueue(Queue* queue, float* data)
{
	if (IfQueueEmpty(queue)) {
		return false;								// 若队列为空则失败
	}
	*data		  = queue->data[queue->front++];	// 获取数据
	queue->front %= queue->size;					// 移动队头
	queue->count--;
	return true;
}

/// @brief 入队
/// @param queue
/// @param data
/// @return 是否成功
bool EnQueue(Queue* queue, float data)
{
	if (IfQueueFull(queue)) {
		return false;							  // 若队列已满则成功
	}
	queue->data[queue->rear++]	= data;			  // 加入数据
	queue->rear				   %= queue->size;	  // 移动队尾
	queue->count++;
	return true;
}

/// @brief 清空队列
/// @param queue
void ClearQueue(Queue* queue)
{
	queue->rear = queue->front = 0;
	queue->count			   = 0;
}

/// @brief 销毁队列
/// @param queue
/// @return 是否成功
bool DeleteQueue(Queue* queue)
{
	if (!queue)
		return false;
	free(queue->data);	  // 释放队列内数据指针
	queue->data = NULL;
	free(queue);		  // 释放队列指针
	queue = NULL;
	return true;
}