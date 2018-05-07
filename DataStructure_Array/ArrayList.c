//
//  ArrayList.c
//  DataStructure
//
//  Created by 刘晋辰 on 2018-05-07.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#include "ArrayList.h"
#include <stdlib.h>

Status AL_InitList(ArrayList* list){
    list->length = 0;
    return OK;
}

Boolean AL_ListEmpty(ArrayList list){
    return list.length == 0;
}

Status AL_ClearList(ArrayList* list){
    list->length = 0;
    return OK;
}

Status AL_GetElem(ArrayList list, unsigned int index, elemType* elem){
    if(index > list.length || list.length == 0 || index < 1){
        printf("Out of index \n");
        return ERROR;
    }
    *elem = list.data[index - 1];
    return OK;
}

unsigned int AL_LocateElem(ArrayList list, elemType elem){
    unsigned int i;
    for (i = 0; i < list.length; ++i)
        if (elem == list.data[i])
            return i+1;
    return 0;
}

Status AL_ListInsert(ArrayList* list, unsigned int index, elemType elem){
    if (index < 1 || index > list->length + 1) {
        printf("Out of index \n");
        return ERROR;
    }
    if (list->length == MAX_SIZE) {
        printf("ArrayList is full \n");
        return ERROR
    }
    if (index <= list->length) {
        for (unsigned int k = list->length - 1; k >= index - 1; k--) {
            list->data[k+1] = list->data[k];
        }
    }
    list->data[index - 1] =elem;
    ++list->length;
    return OK;
}

Status AL_ListDelete(ArrayList* list, unsigned int index, elemType* elem){
    unsigned int k;
    if(AL_ListEmpty(*list)){
        printf("list is empty");
        return ERROR;
    }
    if (index < 1 || index > list->length) {
        printf("Out of index \n");
        return ERROR;
    }
    *elem = list->data[index - 1];
    if (index < list->length) {
        for(k = index; k < list->length; ++k){
            list->data[k - 1] = list->data[k];
        }
    }
    --list->length;
    return OK;
}

unsigned int AL_ListLength(ArrayList list){
    return list.length;
}
