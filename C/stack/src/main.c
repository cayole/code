#include"../inc/stack.h"

int main()
{
    Stack *stack=InitStack(10);
    printf("%d\n",IfStackEmpty(stack));
    printf("%d\n",IfStackFull(stack));
    Push(stack,5);
    Push(stack,9);
    Push(stack,7);
    Push(stack,1);
    printf("%.2f\n",GetTop(stack));
    float t;
    Pop(stack,&t);
    printf("%.2f\n",t);
    ClearStack(stack);
    printf("%.2f\n",GetTop(stack));
    DeleteStack(stack);
    
    return 0;
}