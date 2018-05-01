//
//  Stack.c
//  DataStructure
//
//  Created by 刘晋辰 on 2018-04-30.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#include "LinkStack.h"
#include <stdlib.h>

Status Push(LinkStack* stack, elemType elem){
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = elem;
    s->next = stack->top;
    stack->top = s;
    stack->count++;
    return OK;
}

Status Pop(LinkStack* stack, elemType* elem){
    if(StackEmpty(*stack))
        return ERROR;
    LinkStackPtr s;
    s = stack->top;
    *elem = s->data;
    stack->top = s->next;
    stack->count--;
    free(s);
    return OK;
}

Boolean StackEmpty(LinkStack stack){
    if(!(stack.top))
        return true;
    return false;
}

Status InitStack(LinkStack* stack){
    stack = (LinkStack*)malloc(sizeof(LinkStack));
    if(!stack)
        return ERROR;
    stack->top = NULL;
    stack->count = 0;
    return OK;
}

Status DestoryStack(LinkStack* stack){
    if(!ClearStack(stack))
        return ERROR;
    free(stack);
    return OK;
}

Status ClearStack(LinkStack* stack){
    elemType elem;
    while(stack->top){
        Pop(stack, &elem);
    }
    return OK;
}

Status GetTop(LinkStack* stack, elemType elem){
    LinkStackPtr p;
    p = stack->top;
    if(!p){
        printf("Link Stack is Empty");
        return ERROR;
    }
    elem = p->data;
    return OK;
}

unsigned int StackLength(LinkStack stack){
    return stack.count;
}

