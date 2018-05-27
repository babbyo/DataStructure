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
    s = NULL;
    return OK;
}

Boolean StackEmpty(LinkStack stack){
    if(!(stack.top))
        return true;
    return false;
}

/*Assump stack has allocated memory*/
Status InitStack(LinkStack* stack){
    stack->top = NULL;
    stack->count = 0;
    return OK;
}

Status DestoryStack(LinkStack* stack){
    // for the LinkStack, destory and clear means the same.
    // cause the top pointer is the head pointer
    return ClearStack(stack);
}

Status ClearStack(LinkStack* stack){
    elemType elem;
    Status s;
    while(stack->top){
        s = Pop(stack, &elem);
        if (!s) {
            return ERROR;
        }
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
void StackTraverse(LinkStack stack){
    LinkStackPtr p = stack.top;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

