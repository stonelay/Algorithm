//
//  DoubleLink.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/10.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "DoubleLink.hpp"
#include <stdlib.h>

// 双向链表节点
typedef struct NodeDLink {
    struct NodeDLink *prev;
    struct NodeDLink *next;
    void* p;
} Node;

static Node *pHead = NULL;      // 表头 不存放元素值
static int count = 0;           // 节点个数

// create node
static Node* createNode(void *pVal) {
    Node *pNode = NULL;
    pNode = (Node *)malloc(sizeof(Node));
    if (!pNode) {
        printf("create node error!\n");
        return NULL;
    }
    
    pNode->prev = pNode->next = pNode;  // default 双向循环链表，pre、next默认指向自己
    pNode->p = pVal;                    // 节点的值为pVal
    
    return pNode;
}

static Node* getNode(int index) { // get index node
    if (index < 0 || index >= count) {
        printf("%s failed! index out of bound!\n", __func__);
        return NULL;
    }

    Node *pNode = NULL;
    if (index <= (count / 2)) { // 前半
        int i = index;
        pNode = pHead->next;
        while (i--)
            pNode = pNode->next;
    } else { // 后半
        int j = count - index - 1;
        pNode = pHead->prev;
        while (j--)
            pNode = pNode->prev;
        return pNode;
    }
    
    return pNode;
}

//-------------------------//
int createDLink() {
    pHead = createNode(NULL); // 创建表头
    if (!pHead)
        return -1;
    count = 0;
    return 0;
}

int isEmptyDLink() { // isEmpty
    return count == 0;
}

int sizeDLink() {
    return count;
}

void* getNodeDLink(int index) {
    Node *pindex = getNode(index);
    if (!pindex) {
        printf("%s failed!\n", __func__);
        return NULL;
    }
    return pindex->p;
}

void* getFirstDLink() { // get first node
    return getNodeDLink(0);
}

void* getLastDLink() { // get last node
    return getNodeDLink(count-1);
}

int insertDLink(int index, void* pval) {
    if (index == 0)
        return insertFirstDLink(pval);
    
    Node *pNode = getNode(index);
    if (!pNode)
        return -1;
    
    Node *cNode = createNode(pval);
    if (!cNode)
        return -1;
    
    cNode->prev = pNode->prev;
    cNode->next = pNode;
    pNode->prev->next = cNode;
    pNode->prev = cNode;
    count++;
    return 0;
}

int insertFirstDLink(void *pval) { // insert first node
    Node *cNode = createNode(pval);
    if (!cNode)
        return -1;
    
    cNode->prev = pHead;
    cNode->next = pHead->next;
    pHead->next->prev = cNode;
    pHead->next = cNode;
    count++;
    return 0;
}

int appendLastDLink(void *pval) { // append last node
    Node *cNode = createNode(pval);
    if (!cNode)
        return -1;
    
    cNode->next = pHead;
    cNode->prev = pHead->prev;
    pHead->prev->next = cNode;
    pHead->prev = cNode;
    count++;
    return 0;
}

int deleteNodeDLink(int index) { // delete node
    Node *pNode = getNode(index);
    if (!pNode) {
        printf("%s failed! the index in out of bound!\n", __func__);
        return -1;
    }
    
    pNode->next->prev = pNode->prev;
    pNode->prev->next = pNode->next;
    free(pNode);
    count--;
    return 0;
}

int deleteFirstDLink() { // delete first node
    return deleteNodeDLink(0);
}

int deleteLastDLink() {
    return deleteNodeDLink(count - 1);
}

int destroyDLink() {
    if (!pHead) {
        printf("%s failed! dlink is null!\n", __func__);
        return -1;
    }
    
    Node *pNode = pHead->next;
    Node *ptmp = NULL;
    while(pNode != pHead) {
        ptmp = pNode;
        pNode = pNode->next;
        free(ptmp);
    }
    
    free(pHead);
    pHead = NULL;
    count = 0;
    return 0;
}
