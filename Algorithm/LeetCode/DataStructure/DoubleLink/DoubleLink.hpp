//
//  DoubleLink.hpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/10.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#ifndef DoubleLink_hpp
#define DoubleLink_hpp

#include <stdio.h>

/*
 * 双向循环链表
 */

int createDLink();  // create
int destroyDLink(); // destroy

extern int isEmptyDLink();  // isEmpty
extern int sizeDLink();     // size

extern void* getNodeDLink(int index);       // get index node
extern void* getFirstDLink();               // get first node
extern void* getLastDLink();                // get last node

extern int insertDLink(int index, void *pVal);  // insert index node
extern int insertFirstDLink(void *pVal);        // insert first node
extern int appendLastDLink(void *pVal);         // append last node

extern int deleteNodeDLink(int index);          // delete index node
extern int deleteFirstDLink();                  // delete first node
extern int deleteLastDLink();                   // delete last node

#endif /* DoubleLink_hpp */
