//
//  ArrayStack.c
//  DataStructure
//
//  Created by 刘晋辰 on 2018-05-08.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#include "ArrayStack.h"
#include <stdlib.h>

Status AL_InitStack(ArrayStack* stack){
    stack->top = -1;
    return OK;
}

Status AL_DestoryStack(ArrayStack* stack){
    return AL_ClearStack(stack);
}

Status AL_ClearStack(ArrayStack* stack){
    stack->top = -1;
    return OK;
}

Boolean AL_StackEmpty(ArrayStack stack){
    return stack.top == -1;
}

Status AL_Push(ArrayStack* stack, elemType elem){
    if(stack->top == MAX_SIZE - 1){
        printf("stack is full \n");
        return ERROR;
    }
    ++stack->top;
    stack->data[stack->top] = elem;
    return OK;
}

Status AL_Pop(ArrayStack* stack, elemType* elem){
    if (AL_StackEmpty(*stack)) {
        printf("stack is empty");
        return ERROR;
    }
    *elem = stack->data[stack->top];
    --stack->top;
    return OK;
}

Status AL_GetTop(ArrayStack stack, elemType* elem){
    if (AL_StackEmpty(stack)) {
        printf("stack is empty");
        return ERROR;
    }
    *elem = stack.data[stack.top];
    return OK;
}

unsigned int AL_StackLength(ArrayStack stack){
    return stack.top + 1;
}

void AL_StackTraverse(ArrayStack stack){
    unsigned int k = stack.top;
    if (AL_StackEmpty(stack)) {
        printf("stack is empty");
    }
    while(k != -1){
        printf("%d ", stack.data[k]);
        --k;
    }
    printf("\n");
}
