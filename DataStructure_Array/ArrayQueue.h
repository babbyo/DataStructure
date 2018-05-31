//
//  ArrayQueue.h
//  DataStructure
//
//  Created by 刘晋辰 on 2018-05-27.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#ifndef ArrayQueue_h
#define ArrayQueue_h

#include <stdio.h>
#include "DataStructureUtil.h"

typedef struct{
    elemType data[MAX_SIZE];
    unsigned int front;
    unsigned int rear;        
}ArrayQueue;

Status AL_InitQueue(ArrayQueue* space);
Status AL_DestoryQueue(ArrayQueue* queue);
Status AL_ClearQueue(ArrayQueue* queue);
Boolean AL_QueueEmpty(ArrayQueue queue);
Status AL_GetHead(ArrayQueue queue, elemType* elem);
Status AL_EnQueue(ArrayQueue* queue, elemType elem);
Status AL_DeQueue(ArrayQueue* queue, elemType* elem);
unsigned int AL_QueueLength(ArrayQueue queue);
void AL_QueueTraverse(ArrayQueue queue);

#endif /* ArrayQueue_h */
