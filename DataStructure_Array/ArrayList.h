//
//  ArrayList.h
//  DataStructure
//
//  Created by 刘晋辰 on 2018-05-07.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h

#include <stdio.h>
#include "DataStructureUtil.h"
#define MAX_SIZE 20

typedef struct {
    elemType data[MAX_SIZE];
    unsigned int length;
} ArrayList;

Status AL_InitList(ArrayList* list);
Boolean AL_ListEmpty(ArrayList list);
Status AL_ClearList(ArrayList* list);
Status AL_GetElem(ArrayList list, unsigned int index, elemType* elem);
unsigned int AL_LocateElem(ArrayList list, elemType elem);//一般返回element的时候，声明指针；已知时，声明原变量
Status AL_ListInsert(ArrayList* list, unsigned int index, elemType elem);
Status AL_ListDelete(ArrayList* list, unsigned int index, elemType* elem);
unsigned int AL_ListLength(ArrayList list);



#endif /* ArrayList_h */
