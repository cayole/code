#pragma once
#include "head.h"

typedef enum ListTravelMode { ListHead2Tail, ListTail2Head } ListTravelMode;

typedef struct ListNode {
	float			 data;
	struct ListNode *prev, *next;
} ListNode;

typedef struct List {
	ListNode *head, *tail;	  // 哨兵

} List;

List* InitList(void);																			  // 初始化

bool ListPrevInsert(ListNode* list_node, float data);											  // 前插
bool ListNextInsert(ListNode* List_node, float data);											  // 后插

bool ListHeadInsert(List* list, float data);													  // 头插
bool ListTailInsert(List* list, float data);													  // 尾插

bool ListPrevDelete(ListNode* list_node, float* data);											  // 前删
bool ListNextDelete(ListNode* list_node, float* data);											  // 后删

bool ListHeadDelete(List* list, float* data);													  // 尾删
bool ListTailDelete(List* list, float* data);													  // 头删

ListNode* FindInList(const List* list, float data, const ListTravelMode travel_mode);			  // 查找
bool	  TravelList(const List* list, void (*func)(float), const ListTravelMode travel_mode);	  // 遍历

void DestroyList(List* list);																	  // 销毁链表