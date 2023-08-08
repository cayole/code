#pragma once

#include "head.h"
#define MAX_SIZE 25

typedef struct Stack {
	float* data;	// 栈顶指针
	size_t size;	// 栈大小
	size_t top;		// 栈顶位置
} Stack;
Stack* InitStack(size_t size);
bool   IfStackEmpty(const Stack* stack);
bool   IfStackFull(const Stack* stack);
bool   Push(Stack* stack, float data);
bool   Pop(Stack* stack, float* data);
float  GetTop(const Stack* stack);
void   ClearStack(Stack* stack);
bool   DeleteStack(Stack* stack);
