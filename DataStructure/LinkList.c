//
//  LinkList.c
//  DataStructure
//
//  Created by 刘晋辰 on 2018-04-28.
//  Copyright © 2018 刘晋辰. All rights reserved.
//
// 不能乱free; !p是p为空;
// 声明指针变量一定要初始化；
#include <stdio.h>
#include "LinkList.h"
#include <time.h>

Status InitList(LinkList* list){
    *list = (LinkList)malloc(sizeof(Node));
    if( !list ){
        printf("Out of memory");
        return ERROR;
    }
    (*list)->next = NULL;
    (*list)->data = 0;
    return OK;
};

Boolean ListEmpty(LinkList list){
    if ( !(list->next) ) {
        return true;
    } else {
        return false;
    }
};

Status ClearList(LinkList* list){
    LinkList p,q;
    p = (*list)->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    (*list)->next = NULL;
    return OK;
};

Status GetElem(LinkList list, unsigned int i, elemType* elem){
    LinkList p;
    unsigned int j = 1;
    p = list->next;
    while (p && j < i){
        p = p->next;
        ++j;
    }
    if( !p ){
        printf("Out of Index");
        return ERROR;
    }
    *elem = p->data;
    return OK;
};

Status ListInsert(LinkList* list, unsigned int i, elemType elem){
    LinkList p;
    p = *list;
    unsigned int j = 1;
    while(p && j < i){
        p = p->next;
        ++j;
    }
    if( !p ){
        printf("Out of Index");
        return ERROR;
    }
    LinkList addElem;
    addElem = (LinkList)malloc(sizeof(Node));
    addElem->next = p->next;
    addElem->data = elem;
    p->next = addElem;
    return OK;
}

Status ListDelete(LinkList* list, unsigned int i, elemType* elem){
    LinkList p,q;
    p = *list;
    unsigned int j = 1;
    while(p->next && j < i){
        p = p->next;
        ++j;
    }
    if( !(p->next) ){
        printf("Out of Index");
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *elem = q->data;
    free(q);
    q = NULL;
    return OK;
}

unsigned int ListLength(LinkList list){
    LinkList p;
    unsigned int j = 0;
    p = list->next;
    while (p){
        p = p->next;
        ++j;
    }
    return j;
}

unsigned int LocateElem(LinkList list, elemType elem){
    LinkList p;
    unsigned int j = 1;
    p = list->next;
    if( !p ){
        printf("list is empty. \n");
        return ERROR;
    }
    while (p && p->data != elem){
        p = p->next;
        ++j;
    }
    if( !p ){
        printf("element %d is not in the list", elem);
        return ERROR;
    }
    return j;
}

void CreateListHead(LinkList* list, unsigned int num){
    LinkList p;
    unsigned int i;
    srand((unsigned int)time(0));
    *list = (LinkList)malloc(sizeof(Node));
    (*list)->next = NULL;
    for (i = 0; i < num; ++i){
        p = (LinkList)malloc(sizeof(Node));
        p->next = (*list)->next;
        p->data = (unsigned int) rand()%10 + 1;
        (*list)->next = p;
    }
}

void CreateListTail(LinkList* list, unsigned int num){
    LinkList p, q;
    unsigned int i;
    srand((unsigned int)time(0));
    *list = (LinkList)malloc(sizeof(Node));
    q = *list;
    for (i = 0; i < num; ++i){
        p = (LinkList)malloc(sizeof(Node));
        p->data = (unsigned int) rand()%10 + 1;
        q->next = p;
        q = p;
    }
    q->next = NULL;
}

void ListTraverse(LinkList list){
    LinkList p = list->next;
    if(ListEmpty(list))
        printf("LinkList is empty");
    while(!p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
