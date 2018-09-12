//
//  AVLTreeDisplay.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/12.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "AVLTreeDisplay.hpp"
#include "AVLTree.hpp"

void displayAVLTree(void) {
    
    static int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
    int ilen;
    AVLRoot *root = createAVLTree();
    
    printf("== 高度: %d\n", heightAVLTree(root->node));
    printf("== 依次添加: ");
    ilen = sizeof(arr) / sizeof(int);
    for(int i = 0; i<ilen; i++) {
        printf("%d ", arr[i]);
        insertAVLTree(root, arr[i]);
    }
    
    printf("\n== 前序遍历: ");
    preorderAVLTree(root);
    
    printf("\n== 中序遍历: ");
    inorderAVLTree(root);
    
    printf("\n== 后序遍历: ");
    postorderAVLTree(root);
    printf("\n");
    
    int maxValue, minValue;
    if (maximumAVLTree(root, &maxValue)) {
        printf("== 最大值: %d\n", maxValue);
    }
    if (maximumAVLTree(root, &minValue)) {
        printf("== 最小值: %d\n", minValue);
    }
    
    printf("== 树的详细信息: \n");
    printAVLTree(root);
    
    
    int i = 8;
    printf("\n== 删除根节点: %d", i);
    deleteAVLTree(root, i);
    
    printf("\n== 高度: %d", heightAVLTree(root->node));
    printf("\n== 中序遍历: ");
    inorderAVLTree(root);
    printf("\n== 树的详细信息: \n");
    printAVLTree(root);
    
    // 销毁二叉树
    destroyTreeAVLTree(root);
}
