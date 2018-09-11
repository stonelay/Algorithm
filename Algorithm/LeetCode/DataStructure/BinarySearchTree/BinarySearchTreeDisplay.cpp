//
//  BinarySearchTreeDisplay.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/11.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "BinarySearchTreeDisplay.hpp"
#include "BinarySearchTree.hpp"

void displayBSTree() {
    int ilen;
    BSRoot *root = createBSTree();
    
    int arr[10] = {8, 3, 1, 2, 5, 6, 0, 9, 7, 4};
    ilen = sizeof(arr) / sizeof(int);
    for(int i = 0; i < ilen; i++) {
        insertBSTree(root, arr[i]);
    }
    
    printf("\n== 前序遍历: ");
    preorderBSTree(root);

    printf("\n== 中序遍历: ");
    inorderBSTree(root);

    printf("\n== 后序遍历: ");
    postorderBSTree(root);
    printf("\n");

    int minValue, maxValue;
    if (minimumBSTree(root, &minValue) == 0)
        printf("== 最小值: %d\n", minValue);
    if (maximumBSTree(root, &maxValue) == 0) {
        printf("== 最da值: %d\n", maxValue);
    }
    
    printf("== 树的详细信息: \n");
    printBSTree(root);

    for (int i = 0; i < ilen; i++) {
        printf("\n== 删除节点: %d", arr[i]);
        deleteBSTree(root, arr[i]);
        printf("\n== 遍历");
        inorderBSTree(root);
    }
    printf("\n");

    // 销毁二叉树
    destroyTreeBSTree(root);
}
