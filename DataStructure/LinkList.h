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

Status InitList(LinkList* list);
Boolean ListEmpty(LinkList list);
Status ClearList(LinkList* list);
Status GetElem(LinkList list, unsigned int index, elemType* elem);
unsigned int LocateElem(LinkList list, elemType elem);//一般返回element的时候，声明指针；已知时，声明原变量
Status ListInsert(LinkList* list, unsigned int index, elemType elem);
Status ListDelete(LinkList* list, unsigned int index, elemType* elem);
unsigned int ListLength(LinkList list);
void ListTraverse(LinkList list);
//
void CreateListHead(LinkList* list, unsigned int num);
void CreateListTail(LinkList* list, unsigned int num);


#endif /* LinkList_h */
