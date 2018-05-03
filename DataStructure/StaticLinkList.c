//
//  StaticLinkList.c
//  DataStructure
//
//  Created by 刘晋辰 on 2018-04-30.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#include "StaticLinkList.h"

Status SLL_InitList(StaticLinkList space){
    unsigned int i;
    for(i = 0; i < MAXSIZE - 1; ++i)
        space[i].cur = i+1;
    space[MAXSIZE - 1].cur = 0;
    return OK;
}

unsigned int Malloc_SLL(StaticLinkList space){
    unsigned int i = space[0].cur;
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

Status SLL_ListInsert(StaticLinkList list, unsigned int i, elemType elem){
    unsigned int j, k, l;
    k = MAXSIZE - 1;
    if ( i < 1 || i > SLL_ListLength(list) + 1)
        return ERROR;
    j = Malloc_SLL(list);
    if (j){
        list[j].data = elem;
        for(l = 1; l < i; ++l)
            k = list[k].cur;
        list[j].cur = list[k].cur;
        list[k].cur = j;
        return OK;
    }
    return ERROR;
}

void Free_SLL(StaticLinkList space, unsigned int k){
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

Status SLL_ListDelete(StaticLinkList list, unsigned int i){
    unsigned int j, k, l;
    k = MAXSIZE - 1;
    if ( i < 1 || i > SLL_ListLength(list) + 1)
        return ERROR;
    for(l = 1; l < i; ++l)
        k = list[k].cur;
    j = list[k].cur;
    list[k].cur = list[j].cur;
    Free_SLL(list, j);
    return OK;
}

unsigned int SLL_ListLength(StaticLinkList list){
    unsigned int j, k;
    k = MAXSIZE - 1;
    for (j = 0; list[k].cur != 0; ++j){
        k = list[k].cur;
    }
    return j;
}
