//
//  DoubleLinkDisplay.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/11.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "DoubleLinkDisplay.hpp"
#include "DoubleLink.hpp"

void displayDoubleLink() {
    int iArr[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    
    createDLink();
    for (int i = 0 ; i < 12; i++) {
        appendLastDLink(&iArr[i]);
    }
    
    printf("is empty %d\n", isEmptyDLink());    // 双向链表是否为空
    printf("link size %d\n", sizeDLink());      // 双向链表的大小
    
    int *p;
    for (int i = 0; i < sizeDLink(); i++) {
        p = (int *)getNodeDLink(i);
        printf("index is %d, value is %d\n", i, *p);
    }
    
    destroyDLink();
}
