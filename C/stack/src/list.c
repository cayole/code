#include "../inc/list.h"

List* InitList(void)							  // 初始化
{
	List* list = (List*) malloc(sizeof(List));	  // 创建链表
	if (!list)
		return NULL;

	list->head = (ListNode*) malloc(sizeof(ListNode));	  // 创建头尾指针
	list->tail = (ListNode*) malloc(sizeof(ListNode));
	if ((!list->head) || (!list->tail)) {
		free(list->head);
		free(list->tail);
		free(list);
		return NULL;
	}
	list->head->prev = list->head->next = list->tail;	 // 初始化
	list->tail->prev = list->tail->next = list->head;

	return list;
}

bool ListPrevInsert(ListNode* list_node, float data)			  // 前插
{
	ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));	  // 创建新节点
	if (!new_node) {
		return false;
	}
	new_node->prev		  = list_node->prev;	// 创建新的连接
	new_node->next		  = list_node;			// 创建新的连接
	list_node->prev->next = new_node;			// 修改原有的连接
	list_node->prev		  = new_node;			// 修改原有的连接
	new_node->data		  = data;

	return true;
}
bool ListNextInsert(ListNode* list_node, float data)			  // 后插
{
	ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));	  // 创建新节点
	if (!new_node) {
		return false;
	}
	new_node->next		  = list_node->next;	// 创建新的连接
	new_node->prev		  = list_node;			// 创建新的连接
	list_node->next->prev = new_node;			// 修改原有的连接
	list_node->next		  = new_node;			// 修改原有的连接
	new_node->data		  = data;

	return true;
}

bool ListHeadInsert(List* list, float data)	   // 头插
{
	return (ListNextInsert(list->head, data));
}

bool ListTailInsert(List* list, float data)	   // 尾插
{
	return (ListPrevInsert(list->tail, data));
}

bool ListPrevDelete(ListNode* list_node, float* data)	 // 前删
{
	if (!list_node->prev)
		return false;	 // 判断是否有前节点

	ListNode* del_node	 = list_node->prev;
	del_node->prev->next = list_node;		  // 修改连接关系
	list_node->prev		 = del_node->prev;	  // 修改连接关系
	*data				 = del_node->data;	  // 获取数据
	free(del_node);							  // 释放
	return true;
}

bool ListNextDelete(ListNode* list_node, float* data)	 // 后删
{
	if (!list_node->next)
		return false;	 // 判断是否有后节点

	ListNode* del_node	 = list_node->next;
	del_node->next->prev = list_node;		  // 修改连接关系
	list_node->next		 = del_node->next;	  // 修改连接关系
	*data				 = del_node->data;	  // 获取数据
	free(del_node);							  // 释放
	return true;
}

bool ListHeadDelete(List* list, float* data)	// 尾删
{
	return (ListNextDelete(list->head, data));
}

bool ListTailDelete(List* list, float* data)	// 头删
{
	return (ListPrevDelete(list->tail, data));
}

ListNode* FindInList(const List* list, float data, const ListTravelMode travel_mode)	// 查找
{
	if (travel_mode == ListHead2Tail) {													// 从头寻找
		ListNode* index_node = list->head->next;
		while (index_node != list->tail) {
			if (fabs((index_node->data) - data) < 1e-6) {
				return index_node;
			}
			index_node = index_node->next;
		}
	} else if (travel_mode == ListTail2Head) {	  // 从尾寻找
		ListNode* index_node = list->tail->prev;
		while (index_node != list->head) {
			if (fabs((index_node->data) - data) < 1e-6) {
				return index_node;
			}
			index_node = index_node->prev;
		}
	}
	return NULL;
}

bool TravelList(const List* list, void (*func)(float), const ListTravelMode travel_mode)	// 遍历
{
	ListNode* index_node;
	if (travel_mode == ListHead2Tail) {	   // 从头遍历
		index_node = list->head->next;
		while (index_node != list->tail) {
			func(index_node->data);
			index_node = index_node->next;
		}
		return true;
	} else if (travel_mode == ListTail2Head) {	  // 从尾遍历
		index_node = list->tail->prev;
		while (index_node != list->head) {
			func(index_node->data);
			index_node = index_node->prev;
		}
		return true;
	}
	return false;
}

void DestroyList(List* list)	// 销毁链表
{
	ListNode* list_node = list->head;
	while (!list_node->next) {
		ListNode* del_node	 = list_node->next;
		del_node->next->prev = list_node;		  // 修改连接关系
		list_node->next		 = del_node->next;	  // 修改连接关系
		free(del_node);
	}
	free(list->head);
	free(list->tail);
	free(list);
	list->head = NULL;
	list->tail = NULL;
	list	   = NULL;
}