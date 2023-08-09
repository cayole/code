#include "../inc/stack.h"

/// @brief 创建并初始化栈
/// @param size
/// @return 空栈
Stack* InitStack(size_t size)
{
	if (size < 1) {
		return NULL;
	}
	if (size > MAX_STACK_SIZE) {
		size = MAX_STACK_SIZE;
	}

	Stack* stack = (Stack*) malloc(sizeof(Stack));	  // 创建栈
	if (!stack) {
		return NULL;
	}
	stack->data = (float*) malloc(sizeof(float) * size);
	if (!stack->data) {
		free(stack);
		return NULL;
	}
	stack->size = size;	   // 初始化栈
	stack->top	= 0;

	return stack;
}

/// @brief 判断栈是否为空
/// @param stack
/// @return 是否
bool IfStackEmpty(const Stack* stack) { return (stack->top == 0); }

/// @brief 判断栈是否为满
/// @param stack
/// @return 是否
bool IfStackFull(const Stack* stack) { return (stack->top == stack->size); }

/// @brief 压栈
/// @param stack
/// @param data
/// @return 是否成功
bool Push(Stack* stack, float data)
{
	if (IfStackFull(stack)) {	 // 栈满则失败
		return false;
	}
	stack->data[stack->top++] = data;	 // 加入数据并移动栈顶位置
	return true;
}

/// @brief 出栈
/// @param stack
/// @param data
/// @return 是否成功
bool Pop(Stack* stack, float* data)
{
	if (IfStackEmpty(stack)) {	  // 栈空则失败
		return false;
	}
	*data = stack->data[--stack->top];	  // 输出数据并移动栈顶位置
	return true;
}

/// @brief 获取栈顶数据
/// @param stack
/// @return 栈顶数据
float GetTop(const Stack* stack)
{
	if (IfStackEmpty(stack)) {
		printf("栈为空！\n");
		return 0;
	}
	return stack->data[stack->top - 1];
}

/// @brief 清空栈
/// @param stack
void ClearStack(Stack* stack) { stack->top = 0; }

/// @brief 销毁栈
/// @param stack
/// @return 是否成功
bool DeleteStack(Stack* stack)
{
	if (stack == NULL)
		return false;

	free(stack->data);	  // 释放栈内数据指针
	stack->data = NULL;
	free(stack);		  // 释放栈指针
	stack = NULL;
	return true;
}
