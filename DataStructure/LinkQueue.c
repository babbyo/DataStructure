//
//  LinkQueue.c
//  DataStructure
//
//  Created by 刘晋辰 on 2018-05-02.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#include "LinkQueue.h"
#include <stdlib.h>

Status InitQueue(LinkQueue* space){
    space = (LinkQueue*)malloc(sizeof(LinkQueue));
    if(!space){
        printf("Out of memory");
        return ERROR;
    }
    space->fronter->next = space->rear->next = NULL;
    return OK;
}

Status DestoryQueue(LinkQueue* queue){
    return OK;
}
Status ClearQueue(LinkQueue* queue){
    return ERROR;
}
Boolean QueueEmpty(LinkQueue queue);
Status GetHead(LinkQueue queue, elemType* elem);
Status EnQueue(LinkQueue* queue, elemType elem);
Status DeQueue(LinkQueue* queue, elemType* elem);
unsigned int QueueLength(LinkQueue queue);
