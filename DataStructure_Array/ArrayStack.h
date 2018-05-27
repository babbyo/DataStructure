//
//  ArrayStack.h
//  DataStructure
//
//  Created by 刘晋辰 on 2018-05-08.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#ifndef ArrayStack_h
#define ArrayStack_h

#include <stdio.h>
#include "DataStructureUtil.h"


typedef struct{
    elemType data[MAX_SIZE];
    unsigned int top;
}ArrayStack;

Status AL_InitStack(ArrayStack* stack);
Status AL_DestoryStack(ArrayStack* stack);
Status AL_ClearStack(ArrayStack* stack);
Boolean AL_StackEmpty(ArrayStack stack);
Status AL_Push(ArrayStack* stack, elemType elem);
Status AL_Pop(ArrayStack* stack, elemType* elem);
Status AL_GetTop(ArrayStack stack, elemType* elem);
unsigned int AL_StackLength(ArrayStack stack);
void AL_StackTraverse(ArrayStack stack);

#endif /* ArrayStack_h */
