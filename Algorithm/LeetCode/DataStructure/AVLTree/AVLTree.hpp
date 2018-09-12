//
//  AVLTree.hpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/12.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <stdio.h>

typedef int Value;

typedef struct AVLTreeNode {
    Value value;                    // value
    int height;
    struct AVLTreeNode *left;       // 左孩子
    struct AVLTreeNode *right;      // 右孩子
} Node, *AVLTree;

// avl tree root
typedef struct AVLRoot {
    Node *node;
} AVLRoot;

int heightAVLTree(AVLTree tree);    // height

// traversal
void preorderAVLTree(AVLRoot *root); // preorder
void inorderAVLTree(AVLRoot *root);  // inorder
void postorderAVLTree(AVLRoot *root);// postorder

void printAVLTree(AVLRoot *root);

Node* searchRecursionAVLTree(AVLRoot *root, Value value); // recursion
Node* searchIterativeAVLTree(AVLRoot *root, Value value); // iterative

int minimumAVLTree(AVLRoot *root, int *value);
int maximumAVLTree(AVLRoot *root, int *value);

// create bstree
AVLRoot* createAVLTree();
int insertAVLTree(AVLRoot *root, Value value);
void deleteAVLTree(AVLRoot *root, Value value);

void destroyTreeAVLTree(AVLRoot *root);

#endif /* AVLTree_hpp */
