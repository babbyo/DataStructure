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
    QueuePtr p = (QueuePtr)malloc(sizeof(QueueNode));
    p->next = NULL;
    space->fronter = space->rear = p;
    return OK;
}

// here make sense for destroying the headpointer
Status DestoryQueue(LinkQueue* queue){
    if(!ClearQueue(queue))
        return ERROR;
    free(queue->fronter);
    queue->fronter = queue->rear = NULL;
    return OK;
}

Status ClearQueue(LinkQueue* queue){
    QueuePtr p,q;
    p = queue->fronter->next;
    queue->fronter->next = NULL; //important!!
    queue->rear = queue->fronter;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    return OK;
}

Boolean QueueEmpty(LinkQueue queue){
    if (queue.fronter == queue.rear)
        return true;
    return false;
}

Status GetHead(LinkQueue queue, elemType* elem){
    if( QueueEmpty(queue) ){
        printf("Queue is empty\n");
        return ERROR;
    }
    *elem = queue.fronter->next->data;
    return OK;
}

Status EnQueue(LinkQueue* queue, elemType elem){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QueueNode));
    if (!p) {
        printf("Out of memory\n");
        return ERROR;
    }
    p->data = elem;
    p->next = NULL;
    queue->rear->next = p;
    queue->rear = p;
    return OK;
}

Status DeQueue(LinkQueue* queue, elemType* elem){
    QueuePtr p;
    if ( QueueEmpty(*queue) ) {
        printf("Queue is empty");
        return ERROR;
    }
    p = queue->fronter->next;
    *elem = p->data;
    queue->fronter->next = p->next;
    if (p == queue->rear)
        queue->rear = queue->fronter;
    free(p);
    return OK;
}

unsigned int QueueLength(LinkQueue queue){
    QueuePtr p = queue.fronter->next;
    if(!(queue.fronter)){
        printf("Queue is destoried \n");
        return 0;
    }
    unsigned int i = 0;
    while( !p ){
        p = p->next;
        ++i;
    }
    return i;
}

void QueueTraverse(LinkQueue queue){
    QueuePtr p;
    p = queue.fronter->next;
    if(QueueEmpty(queue))
        printf("Queue is empty");
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
