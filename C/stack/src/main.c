#include "../inc/main.h"

int main()
{
	Queue* queue = InitQueue(8);

	EnQueue(queue, 10);
	EnQueue(queue, 9);
	EnQueue(queue, 8);
	EnQueue(queue, 7);

	float rec;
	DeQueue(queue, &rec);
	printf("%.2f\n", rec);
	DeQueue(queue, &rec);
	printf("%.2f\n", rec);
	DeQueue(queue, &rec);
	printf("%.2f", rec);

	return 0;
}