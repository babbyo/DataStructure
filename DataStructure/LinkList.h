//
//  LinkList.h
//  DataStructure
//
//  Created by 刘晋辰 on 2018-04-28.
//  Copyright © 2018 刘晋辰. All rights reserved.
//
#ifndef LinkList_h
#define LinkList_h

#include <stdlib.h>
#include "DataStructureUtil.h"

typedef struct Node{
    elemType data;
    struct Node* next;
} Node;
typedef Node* LinkList;

Status LL_InitList(LinkList list);
Boolean LL_ListEmpty(LinkList list);
Status LL_ClearList(LinkList list);
Status LL_GetElem(LinkList list, unsigned int index, elemType* elem);
unsigned int LL_LocateElem(LinkList list, elemType elem);//一般返回element的时候，声明指针；已知时，声明原变量
Status LL_ListInsert(LinkList list, unsigned int index, elemType elem);
Status LL_ListDelete(LinkList list, unsigned int index, elemType* elem);
unsigned int LL_ListLength(LinkList list);
//
void LL_CreateListHead(LinkList list, unsigned int num);
void LL_CreateListTail(LinkList list, unsigned int num);


#endif /* LinkList_h */
