#include "../inc/main.h"

int main()
{
	Stack* stack = InitStack(10);
	Queue* queue = InitQueue(10);

	for (int i = 0; i < 10; i++) {
		EnQueue(queue, i);
		Push(stack, i);
	}

	printf("IfStackEmpty=%d\n", IfStackEmpty(stack));
	printf("IfQueueEmpty=%d\n", IfQueueEmpty(queue));
	printf("IfStackFull=%d\n", IfStackFull(stack));
	printf("IfQueueFull=%d\n", IfQueueFull(queue));

	float rec;
	for (int i = 0; i < 4; i++) {
		Pop(stack, &rec);
		printf("%.2f\n", rec);
		DeQueue(queue, &rec);
		printf("%.2f\n", rec);
	}

	ClearStack(stack);
	ClearQueue(queue);
	printf("IfStackEmpty=%d\n", IfStackEmpty(stack));
	printf("IfQueueEmpty=%d\n", IfQueueEmpty(queue));

	DeleteStack(stack);
	DeleteQueue(queue);

	return 0;
}