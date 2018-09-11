//
//  RBTree.hpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/5.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#ifndef RBTree_hpp
#define RBTree_hpp

#include <stdio.h>

// color
typedef enum {
    nodeColorRed    = 0, // red
    nodeColorBlack  = 1, // black
} NodeColor;

typedef int Value;

// rb three node
typedef struct RBTreeNode {
    NodeColor color;                // color
    Value  value;                   // value
    struct RBTreeNode *left;        // left child
    struct RBTreeNode *right;       // right child
    struct RBTreeNode *parent;      // parent child
} Node, *RBTree;

// rb three root
typedef struct rbRoot {
    Node *node;
} RBRoot;

RBRoot* createRBTree();                         // create
void destroyRBTree(RBRoot *root);               // destroy
int insertRBTree(RBRoot *root, Value value);    // insert
void deleteRBTree(RBRoot *root, Value value);   // delete

// traversal
void preorderRBTree(RBRoot *root);      // preorder
void inorderRBTree(RBRoot *root);       // inorder
void postorderRBTree(RBRoot *root);     // postorder

// search
int searchRecursionRBTree(RBRoot *root, Value value);       // recursion search
int searchIterativeRBTree(RBRoot *root, Value value);       // iterative search

int minimumRBTree(RBRoot *root, int *val);  // minimum
int maximumRBTree(RBRoot *root, int *val);  // maximum

void printRBTree(RBRoot *root); // print

#endif /* RBTree_hpp */
