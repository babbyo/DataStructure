//
//  StaticLinkList.h
//  DataStructure
//
//  Created by 刘晋辰 on 2018-04-30.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#ifndef StaticLinkList_h
#define StaticLinkList_h

#include <stdio.h>

typedef int elemType;
typedef int Status;
#define ERROR 0
#define OK 1
#define true 1
#define false 0

#define MAXSIZE 1000
typedef struct {
    elemType data;
    int cur; // 游标
}Component, StaticLinkList[MAXSIZE];

Status SLL_InitList(StaticLinkList space);
unsigned int Malloc_SLL(StaticLinkList space);
Status SLL_ListInsert(StaticLinkList list, unsigned int i, elemType elem);
Status SLL_ListDelete(StaticLinkList list, unsigned int i);
void Free_SLL(StaticLinkList list, unsigned int k);
unsigned int SLL_ListLength(StaticLinkList space);

#endif /* StaticLinkList_h */
