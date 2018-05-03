//
//  main.c
//  DataStructure
//
//  Created by 刘晋辰 on 2018-04-28.
//  Copyright © 2018 刘晋辰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "StaticLinkList.h"
#include "LinkList.h"
#include "LinkStack.h"



int main(int argc, const char * argv[]) {
    // insert code here...
    LinkStack stack;
    InitStack(&stack);
    Push(&stack, 10);
    Push(&stack, 10);
    Push(&stack, 10);
    ClearStack(&stack);
    printf("Hello, World!\n");
    printf("done\n");
    return 0;
}
