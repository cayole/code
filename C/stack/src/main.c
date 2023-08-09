#include "../inc/main.h"

int main()							 // 测试案例
{
	Stack* stack = InitStack(10);	 // 创建容量为10的栈
	Queue* queue = InitQueue(10);	 // 创建容量为10的队列
	List*  list	 = InitList();		 // 创建空链表

	for (int i = 0; i < 10; i++) {
		EnQueue(queue, i);				 // 向队列内加入数据
		Push(stack, i);					 // 向栈内加入数据
		ListTailInsert(list, i);		 // 向链表尾部加入数据
		ListHeadInsert(list, 10 - i);	 // 向链表头部加入数据
	}

	printf("IfStackEmpty=%d\n", IfStackEmpty(stack));
	printf("IfQueueEmpty=%d\n", IfQueueEmpty(queue));
	printf("IfStackFull=%d\n", IfStackFull(stack));
	printf("IfQueueFull=%d\n", IfQueueFull(queue));

	float temp;
	ListPrevDelete(FindInList(list, 4, 0), &temp);
	ListNextDelete(FindInList(list, 4, 0), &temp);
	ListPrevInsert(FindInList(list, 4, 0), 10);
	ListNextInsert(FindInList(list, 4, 0), 10);

	void print(float a) { printf("list:%.2f\n\n", a); }
	TravelList(list, print, 0);

	float rec;
	for (int i = 0; i < 4; i++) {
		Pop(stack, &rec);			   // 出栈
		printf("stack:%.2f\n", rec);
		DeQueue(queue, &rec);		   // 出队
		printf("queue:%.2f\n", rec);
		ListHeadDelete(list, &rec);	   // 删除链表头部元素
		printf("list:%.2f\n", rec);
		ListTailDelete(list, &rec);	   // 删除链表尾部元素
		printf("list:%.2f\n", rec);
	}

	ClearStack(stack);
	ClearQueue(queue);
	printf("IfStackEmpty=%d\n", IfStackEmpty(stack));
	printf("IfQueueEmpty=%d\n", IfQueueEmpty(queue));

	DeleteStack(stack);
	DeleteQueue(queue);
	DestroyList(list);

	return 0;
}