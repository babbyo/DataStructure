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
