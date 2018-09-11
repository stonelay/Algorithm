//
//  BinarySearchTree.hpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/11.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>

typedef int Value;

typedef struct BSTreeNode{
    Value  value;                   // value
    struct BSTreeNode *left;        // left child
    struct BSTreeNode *right;       // right child
    struct BSTreeNode *parent;      // parent child
} Node, *BSTree;

// rb tree root
typedef struct bsRoot {
    Node *node;
} BSRoot;

// create bstree
BSRoot* createBSTree();
void destroyTreeBSTree(BSRoot *root);
int insertBSTree(BSRoot *root, Value value);
void deleteBSTree(BSRoot *root, Value value);

// traversal
void preorderBSTree(BSRoot *root);   // preorder
void inorderBSTree(BSRoot *root);    // inorder
void postorderBSTree(BSRoot *root); // postorder

Node* searchRecursionBSTree(BSRoot *root, Value value); // search recursion
Node* searchIterativeBSTree(BSRoot *root, Value value); // search iterative

int minimumBSTree(BSRoot *root, int *value);
int maximumBSTree(BSRoot *root, int *value);

Node* successorBSTree(Node *node);  // 后继节点
Node* predecessorBSTree(Node *node);// 前驱节点

void printBSTree(BSRoot *root);

#endif /* BinarySearchTree_hpp */
