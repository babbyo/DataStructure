//
//  Stack.h
//  DataStructure
//
//  Created by 刘晋辰 on 2018-04-30.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>
#define OK 1;
#define ERROR 0;
#define true 1;
#define false 0;

typedef int Status;
typedef int Boolean;
typedef int elemType;
typedef struct StackNode{
    elemType data;
    struct StackNode* next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    unsigned int count;
} LinkStack;

Status InitStack(LinkStack* stack);
Status DestoryStack(LinkStack* stack);
Status ClearStack(LinkStack* stack);
Boolean StackEmpty(LinkStack stack);
Status Push(LinkStack* stack, elemType elem);
Status Pop(LinkStack* stack, elemType* elem);
Status GetTop(LinkStack* stack, elemType elem);
unsigned int StackLength(LinkStack stack);


#endif /* LinkStack_h */
