//
//  RBTreeDisplay.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/5.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "RBTreeDisplay.hpp"
#include "RBTree.hpp"

void displayRBTree() {
    int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int aLen = sizeof(a) / sizeof(int);
    
    RBRoot *root=NULL;
    
    root = createRBTree();
    printf("== 原始数据: ");
    for(int i = 0; i < aLen; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    for (int i = 0; i < aLen; i++) {
        insertRBTree(root, a[i]);
        printf("== 添加节点: %d\n", a[i]);
        printf("== 树的详细信息: \n");
        printRBTree(root);
        printf("\n");
    }
    
    printf("== 前序遍历: ");
    preorderRBTree(root);
    
    printf("\n== 中序遍历: ");
    inorderRBTree(root);
    
    printf("\n== 后序遍历: ");
    postorderRBTree(root);
    printf("\n");
    
    int minValue, maxValue;
    if (minimumRBTree(root, &minValue)==0)
        printf("== 最小值: %d\n", minValue);
    if (maximumRBTree(root, &maxValue)==0)
        printf("== 最大值: %d\n", maxValue);
    printf("== 树的详细信息: \n");
    printRBTree(root);
    printf("\n");
    
    for(int i = 0; i < aLen; i++) {
        deleteRBTree(root, a[i]);
        printf("== 删除节点: %d\n", a[i]);
        if (root) {
            printf("== 树的详细信息: \n");
            printRBTree(root);
            printf("\n");
        }
    }
    
    destroyRBTree(root);
}
