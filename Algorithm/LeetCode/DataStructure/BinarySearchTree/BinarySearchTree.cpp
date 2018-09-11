//
//  BinarySearchTree.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/11.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "BinarySearchTree.hpp"
#include <stdlib.h>

// create bstree
BSRoot* createBSTree() {
    BSRoot *root = (BSRoot *)malloc(sizeof(BSRoot));
    root->node = NULL;
    return root;
}

// preorder
static void preorder(BSTree tree) {
    if(tree != NULL) {
        printf("%d ", tree->value);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void preorderBSTree(BSRoot *root) {
    if (root)
        preorder(root->node);
}

// inorder
static void inorder(BSTree tree) {
    if(tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->value);
        inorder(tree->right);
    }
}

void inorderBSTree(BSRoot *root) {
    if (root) {
        inorder(root->node);
    }
}

// postorder
void postorder(BSTree tree) {
    if(tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->value);
    }
}

void postorderBSTree(BSRoot *root) {
    if (root) {
        postorder(root->node);
    }
}

/*
 * (递归实现)查找"二叉树x"中键值为value的节点
 */
Node* searchRecursion(BSTree tree, Value value) {
    if (tree == NULL || tree->value == value)
        return tree;
    
    if (value < tree->value)
        return searchRecursion(tree->left, value);
    else
        return searchRecursion(tree->right, value);
}

Node *searchRecursionBSTree(BSTree tree, Value value) {
    return searchRecursion(tree, value);
}

/*
 * (非递归实现)查找 值为value的节点
 */
Node* searchIterative(BSTree tree, Value value) {
    while ((tree != NULL) && (tree->value != value)) {
        if (value < tree->value)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}

Node* searchIterativeBSTree(BSTree tree, Value value) {
    return searchIterative(tree, value);
}

/*
 * 查找最小结点：返回tree为根结点的二叉树的最小结点。
 */
static Node* minimum(BSTree tree) {
    if (tree == NULL)
        return NULL;
    
    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

int minimumBSTree(BSRoot *root, int *value) {
    if (root == NULL) {
        return -1;
    }
    
    Node *node = minimum(root->node);
    if (node == NULL)
        return -1;
    
    *value = node->value;
    return 0;
}

/*
 * 查找最大结点：返回tree为根结点的二叉树的最大结点。
 */
static Node* maximum(BSTree tree) {
    if (tree == NULL)
        return NULL;
    
    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

int maximumBSTree(BSRoot *root, int *value) {
    if (root == NULL) {
        return -1;
    }
    
    Node *node = maximum(root->node);
    if (node == NULL)
        return -1;
    
    *value = node->value;
    return 0;
}

/*
 * 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
 */
Node* successorBSTree(Node *x) {
    // 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
    if (x->right != NULL)
        return minimum(x->right);
    
    // 如果x没有右孩子。则x有以下两种可能：
    // (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
    // (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
    Node* y = x->parent;
    while ((y != NULL) && (x == y->right)) {
        x = y;
        y = y->parent;
    }
    return y;
}

/*
 * 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
 */
Node* predecessorBSTree(Node *x) {
    // 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
    if (x->left != NULL)
        return maximum(x->left);
    
    // 如果x没有左孩子。则x有以下两种可能：
    // (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
    // (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
    Node* y = x->parent;
    while ((y != NULL) && (x == y->left)) {
        x = y;
        y = y->parent;
    }
    return y;
}

/*
 * 创建并返回二叉树结点。
 */
static Node* createNodeBSTree(Value value, Node *parent, Node *left, Node* right) {
    Node* p;
    
    if ((p = (Node *)malloc(sizeof(Node))) == NULL)
        return NULL;
    p->value = value;
    p->left = left;
    p->right = right;
    p->parent = parent;
    
    return p;
}

/*
 * 将结点插入到二叉树中
 */
static void insertBSTree(BSRoot *root, Node *z) {
    Node *y = NULL;
    Node *x = root->node;
    
    // 查找z的插入位置
    while (x != NULL) {
        y = x;
        if (z->value < x->value)
            x = x->left;
        else
            x = x->right;
    }
    
    z->parent = y;
    if (y == NULL)
        root->node = z;
    else if (z->value < y->value)
        y->left = z;
    else
        y->right = z;
}

/*
 * 新建结点(value)，并将其插入到二叉树中
 */
int insertBSTree(BSRoot *root, Value value) {
    Node *z;
    if ((z = createNodeBSTree(value, NULL, NULL, NULL)) == NULL)
        return -1;
    insertBSTree(root, z);
    return 0;
}

/*
 * 删除结点(z)，并返回根节点
 */
static void deleteBSTree(BSRoot *root, Node *z) {
    Node *x = NULL;
    Node *y = NULL;
    
    if ((z->left == NULL) || (z->right == NULL))
        y = z;
    else
        y = successorBSTree(z);
    
    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;
    
    if (x != NULL)
        x->parent = y->parent;
    
    if (y->parent == NULL)
        root->node = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    
    if (y != z)
        z->value = y->value;
    
    if (y!=NULL)
        free(y);
}

void deleteBSTree(BSRoot *root, Value value) {
    Node *z;
    if ((z = searchRecursion(root->node, value)) != NULL)
        deleteBSTree(root, z);
}

/*
 * 销毁二叉树
 */
static void destroyBSTree(BSTree tree) {
    if (tree == NULL)
        return;
    
    if (tree->left != NULL)
        destroyBSTree(tree->left);
    if (tree->right != NULL)
        destroyBSTree(tree->right);
    
    free(tree);
}

void destroyTreeBSTree(BSRoot *root) {
    destroyBSTree(root->node);
}

/*
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
void printBSTree(BSTree tree, Value value, int direction) {
    if(tree != NULL) {
        if(direction==0)    // tree是根节点
            printf("%2d is root\n", tree->value);
        else                // tree是分支节点
            printf("%2d is %2d's %6s child\n", tree->value, value, direction==1?"right" : "left");
        
        printBSTree(tree->left, tree->value, -1);
        printBSTree(tree->right,tree->value,  1);
    }
}

void printBSTree(BSRoot *root) {
    if (root != NULL && root->node != NULL)
        printBSTree(root->node, root->node->value, 0);
}
