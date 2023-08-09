# 栈、队列和链表
## 1.1 栈
栈是一种后进先出的数据结构。栈的基本操作包括创建栈，销毁栈，入栈,出栈，判断栈满、栈空等。
本代码使用结构体Stack封装栈。函数InitStack用来创建并初始化栈，函数IfStackEmpty用来判断栈是否为空，函数IfStackFull用来判断栈是否为满，函数Push用来入栈，函数Pop用来弹出栈顶元素，函数GetTop用来获取栈顶元素的值，函数ClearStack用来清除栈，函数DeleteStack用来销毁栈。
## 1.2 队列
队列是一种后进先出的数据结构。队列的基本操作包括创建队列，销毁队列，入队,出队，判断队满、队空等。
本代码使用结构体Queue封装队列。函数InitQueue用来创建并初始化队列，函数IfQueueEmpty用来判断队列是否为空，函数IfQueueFull用来判断队列是否为满，函数EnQueue用来入队，函数DeQueue用来出队，函数ClearQueue用来清除队列，函数DeleteQueue用来销毁队列。
## 1.3 链表
链表是一种物理存储上非连续，数据元素的逻辑顺序通过链表中的指针链接次序，实现的一种线性存储结构。
与数组相比，链表在插入或删除数据上比数组更为优越，即可以通过直接修改前后相邻数据之间的关系来进行插入或删除数据。但是链表访问数据上就不如数组优越，每次访问都需要进行遍历。
本代码使用结构体ListNode来实现链表节点，
用结构体List来封装头尾哨兵节点来实现双向链表，
用函数InitList实现链表初始化，
用函数ListPrevInsert实现前插，
用函数ListNextInsert实现后插，
用函数ListHeadInsert实现头插，
用函数ListTailInsert实现尾插，
用函数ListPrevDelete实现前删，
用函数ListNextDelete实现后删，
用函数ListHeadDelete实现尾删，
用函数ListTailDelete实现头删，
用函数FindInList实现查找，
用函数TravelList实现遍历，
用函数DestroyList实现销毁。