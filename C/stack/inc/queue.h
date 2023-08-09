#pragma once

#include "head.h"

#define MAX_Queue_SIZE 25	 // 队列的最大容量
typedef struct Queue {
	float* data;
	size_t front, rear, size, count;
} Queue;

Queue* InitQueue(size_t size);				  // 创建并初始化队列
bool   DeQueue(Queue* queue, float* data);	  // 出队
bool   EnQueue(Queue* queue, float data);	  // 入队
bool   IfQueueFull(const Queue* queue);		  // 判断队列是否为满
bool   IfQueueEmpty(const Queue* queue);	  // 判断队列是否为空
void   ClearQueue(Queue* queue);			  // 清空队列
bool   DeleteQueue(Queue* queue);			  // 销毁队列
