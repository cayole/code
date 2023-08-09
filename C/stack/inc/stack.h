#pragma once

#include "head.h"
#define MAX_STACK_SIZE 25	 // 栈最大容量

typedef struct Stack {
	float* data;							// 存储的数据
	size_t size;							// 栈的容量
	size_t top;								// 栈顶位置
} Stack;
Stack* InitStack(size_t size);				// 创建并初始化栈
bool   IfStackEmpty(const Stack* stack);	// 判断栈是否为空
bool   IfStackFull(const Stack* stack);		// 判断栈是否为满
bool   Push(Stack* stack, float data);		// 压栈
bool   Pop(Stack* stack, float* data);		// 出栈
float  GetTop(const Stack* stack);			// 获取栈顶数据
void   ClearStack(Stack* stack);			// 清空栈
bool   DeleteStack(Stack* stack);			// 销毁栈
