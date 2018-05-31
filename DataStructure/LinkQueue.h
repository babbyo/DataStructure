//
//  LinkQueue.h
//  DataStructure
//
//  Created by 刘晋辰 on 2018-05-02.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#ifndef LinkQueue_h
#define LinkQueue_h

#include <stdio.h>
#include "DataStructureUtil.h"

typedef struct QueueNode{
    elemType data;
    struct QueueNode* next;
} QueueNode, *QueuePtr;
typedef struct {
    QueuePtr fronter,rear;
}LinkQueue;

Status InitQueue(LinkQueue* space);
Status DestoryQueue(LinkQueue* queue);
Status ClearQueue(LinkQueue* queue);
Boolean QueueEmpty(LinkQueue queue);
Status GetHead(LinkQueue queue, elemType* elem);
Status EnQueue(LinkQueue* queue, elemType elem);
Status DeQueue(LinkQueue* queue, elemType* elem);
unsigned int QueueLength(LinkQueue queue);
void QueueTraverse(LinkQueue queue);


#endif /* LinkQueue_h */
