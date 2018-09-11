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

int isEmptyDLink();  // isEmpty
int sizeDLink();     // size

void* getNodeDLink(int index);       // get index node
void* getFirstDLink();               // get first node
void* getLastDLink();                // get last node

int insertDLink(int index, void *pVal);  // insert index node
int insertFirstDLink(void *pVal);        // insert first node
int appendLastDLink(void *pVal);         // append last node

int deleteNodeDLink(int index);          // delete index node
int deleteFirstDLink();                  // delete first node
int deleteLastDLink();                   // delete last node

#endif /* DoubleLink_hpp */
