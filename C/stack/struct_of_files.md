~~~mermaid
graph LR
    head[head.h]---list[list.h]
    head---queue[queue.h]
    head---stack[stack.h]
    list---main[main.h]
    queue---main
    stack---main
    list===ist.c[list.c]
    queue===queue.c[queue.c]
    stack===stack.c[stack.c]
    main===main.c[main.c]
~~~