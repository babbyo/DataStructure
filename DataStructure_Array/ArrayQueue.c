//
//  ArrayQueue.c
//  DataStructure
//
//  Created by 刘晋辰 on 2018-05-27.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#include "ArrayQueue.h"

Status AL_InitQueue(ArrayQueue* space){
    space->front = space->rear = 0;
    return OK;
}

Status AL_DestoryQueue(ArrayQueue* queue){
    queue->front = queue->rear = 0;
    return OK;
}

Status AL_ClearQueue(ArrayQueue* queue){
    queue->rear = queue->front;
    return OK;
}

Boolean AL_QueueEmpty(ArrayQueue queue){
    return queue.rear == queue.front;
}

Status AL_GetHead(ArrayQueue queue, elemType* elem){
    if(AL_QueueEmpty(queue)){
        printf("Queue is empty \n");
        return ERROR;
    }
    *elem = queue.data[queue.front];
    return OK;
}

Status AL_EnQueue(ArrayQueue* queue, elemType elem){
    if ( (queue->rear + 1)%MAX_SIZE == queue->front){
        printf("queue is full \n");
        return ERROR;
    }
    queue->data[queue->rear] = elem;
    queue->rear = (queue->rear + 1)%MAX_SIZE;
    return OK;
}

Status AL_DeQueue(ArrayQueue* queue, elemType* elem){
    if(AL_QueueEmpty(*queue)){
        printf("Queue is empty \n");
        return ERROR;
    }
    *elem = queue->data[queue->front];
    queue->front = (queue->front + 1)%MAX_SIZE;
    return OK;
}

unsigned int AL_QueueLength(ArrayQueue queue){
    return (queue.rear - queue.front + MAX_SIZE)%MAX_SIZE;
}

void AL_QueueTraverse(ArrayQueue queue){
    if(AL_QueueEmpty(queue))
        printf("Queue is empty");
    unsigned int i = queue.front;
    while((i+queue.front)!=queue.rear)
    {
        printf("%d ", queue.data[i]);
        i=(i+1)%MAX_SIZE;
    }
    printf("\n");
}



