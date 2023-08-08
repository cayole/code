#pragma once

#include "head.h"
#define MAX_SIZE 25

typedef struct Stack {
	float* data;
	size_t size;
	size_t top;
} Stack;
Stack* InitStack(size_t size);
bool   IfStackEmpty(const Stack* stack);
bool   IfStackFull(const Stack* stack);
bool   Push(Stack* stack, float data);
bool   Pop(Stack* stack, float* data);
float  GetTop(const Stack* stack);
void   ClearStack(Stack* stack);
bool   DeleteStack(Stack* stack);
