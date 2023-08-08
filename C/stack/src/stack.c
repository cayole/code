#include"../inc/stack.h"

Stack* InitStack(size_t size)
{
    if(size<1)
    {
        return NULL;
    }
    if(size>MAX_SIZE)
    {
        size=MAX_SIZE;
    }
    
    Stack* stack=(Stack*)malloc(sizeof(Stack)*size);
    if(!stack)
    {
        return NULL;
    }
    stack->data=(float*)malloc(sizeof(float)*size);
    if(!stack->data)
    {
        free(stack);
        return NULL;
    }
    stack->size=size;
    stack->top=0;

    return stack;
}


bool IfStackEmpty(const Stack *stack)
{
    return (stack->top==0);
}

bool IfStackFull(const Stack *stack)
{
    return (stack->top==stack->size);
}

bool Push(Stack *stack,float data)
{
    if(IfStackFull(stack))
    {
        return false;
    }
    stack->data[stack->top++]=data;
    return true;
}

bool Pop(Stack *stack,float *data)
{
    if(IfStackEmpty(stack))
    {
        return false;
    }
    *data=stack->data[--stack->top];
    return true;
}

float GetTop(const Stack *stack)
{
    if(IfStackEmpty(stack))
    {
        return 0;
    }
    return stack->data[stack->top-1];
}

void ClearStack(Stack *stack)
{
    stack->top=0;
}

bool DeleteStack(Stack *stack)
{
    if(stack==NULL)
        return false;

    free(stack->data);
    stack->data=NULL;
    free(stack);
    stack=NULL;
    return true;
}

