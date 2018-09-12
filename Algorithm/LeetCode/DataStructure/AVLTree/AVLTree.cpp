//
//  AVLTree.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/12.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "AVLTree.hpp"
#include <stdlib.h>

int maxInt(int a, int b) {
    return a > b ? a : b;
}

int heightAVLTree(AVLTree tree) { // avl tree height
    return tree == NULL ? -1 : tree->height;
}

// preorder
void preorder(AVLTree tree) {
    if(tree != NULL) {
        printf("%d ", tree->value);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void preorderAVLTree(AVLRoot *root) {
    preorder(root->node);
}

// inorder
void inorder(AVLTree tree) {
    if(tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->value);
        inorder(tree->right);
    }
}

void inorderAVLTree(AVLRoot *root) {
    inorder(root->node);
}

// postorder
void postorder(AVLTree tree) {
    if(tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->value);
    }
}

void postorderAVLTree(AVLRoot *root) {
    postorder(root->node);
}

// search recursion
Node* searchRecursion(AVLTree tree, Value value) {
    if (tree == NULL || tree->value == value)
        return tree;
    
    if (value < tree->value)
        return searchRecursion(tree->left, value);
    else
        return searchRecursion(tree->right, value);
}

Node* searchRecursionAVLTree(AVLRoot *root, Value value) {
    return searchRecursion(root->node, value);
}

// search iterative
Node* searchIterative(AVLTree tree, Value value) {
    while ((tree != NULL) && (tree->value != value)) {
        if (value < tree->value)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}

Node *searchIterativeAVLTree(AVLRoot *root, Value value) {
    return searchIterative(root->node, value);
}

// minimum
static Node* minimum(AVLTree tree) {
    if (tree == NULL)
        return NULL;
    
    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

int minimumAVLTree(AVLRoot *root, int *value) {
    if (root == NULL) {
        return -1;
    }
    
    Node *node = minimum(root->node);
    if (node == NULL)
        return -1;
    
    *value = node->value;
    return 0;
}

// maximum
static Node* maximum(AVLTree tree) {
    if (tree == NULL)
        return NULL;
    
    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

int maximumAVLTree(AVLRoot *root, int *value) {
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
 * LL：左左对应的情况(左单旋转)。
 *
 * 返回值：旋转后的根节点
 */
static Node* rotationLL(AVLTree k2) {
    AVLTree k1;
    
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    
    k2->height = maxInt(heightAVLTree(k2->left), heightAVLTree(k2->right)) + 1;
    k1->height = maxInt(heightAVLTree(k1->left), k2->height) + 1;
    
    return k1;
}

/*
 * RR：右右对应的情况(右单旋转)。
 *
 * 返回值：旋转后的根节点
 */
static Node* rotationRR(AVLTree k1) {
    AVLTree k2;
    
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    
    k1->height = maxInt(heightAVLTree(k1->left), heightAVLTree(k1->right)) + 1;
    k2->height = maxInt(heightAVLTree(k2->right), k1->height) + 1;
    
    return k2;
}

/*
 * LR：左右对应的情况(左双旋转)。
 *
 * 返回值：旋转后的根节点
 */
static Node* rotationLR(AVLTree k3) {
    k3->left = rotationRR(k3->left);
    return rotationLL(k3);
}

/*
 * RL：右左对应的情况(右双旋转)。
 *
 * 返回值：旋转后的根节点
 */
static Node* rotationRL(AVLTree k1) {
    k1->right = rotationLL(k1->right);
    return rotationRR(k1);
}

/*
 * 创建AVL树结点。
 */
static Node* createNodeAVLTree(Value value, Node *left, Node* right) {
    Node* p;
    if ((p = (Node *)malloc(sizeof(Node))) == NULL)
        return NULL;
    p->value = value;
    p->height = 0;
    p->left = left;
    p->right = right;
    return p;
}

/*
 * 将结点插入到AVL树中
 */
static Node* insertAVLTree(AVLTree tree, Node *node) {
    
    if (tree == NULL) {
        tree = node;
    } else if (node->value < tree->value) { // 应该将key插入到"tree的左子树"的情况
        tree->left = insertAVLTree(tree->left, node);
        // 插入节点后，若AVL树失去平衡，则进行相应的调节。
        if (heightAVLTree(tree->left) - heightAVLTree(tree->right) == 2) {
            if (node->value < tree->left->value)
                tree = rotationLL(tree);
            else
                tree = rotationLR(tree);
        }
    } else if (node->value > tree->value) { // 应该将key插入到"tree的右子树"的情况
        tree->right = insertAVLTree(tree->right, node);
        // 插入节点后，若AVL树失去平衡，则进行相应的调节。
        if (heightAVLTree(tree->right) - heightAVLTree(tree->left) == 2) {
            if (node->value > tree->right->value)
                tree = rotationRR(tree);
            else
                tree = rotationRL(tree);
        }
    } else { //key == tree->key)
        printf("添加失败：不允许添加相同的节点！\n");
    }
    tree->height = maxInt(heightAVLTree(tree->left), heightAVLTree(tree->right)) + 1;
    return tree;
}

AVLRoot* createAVLTree() {
    AVLRoot *root = (AVLRoot *)malloc(sizeof(AVLRoot));
    root->node = NULL;
    return root;
}

int insertAVLTree(AVLRoot *root, Value value) {
    Node *z;
    if ((z = createNodeAVLTree(value, NULL, NULL)) == NULL)
        return -1;
    root->node = insertAVLTree(root->node, z);
    
    return 0;
}

/*
 * 删除结点(z)，返回根节点
 */
static Node* deleteAVLTree(AVLTree tree, Node *z) {
    // 根为空 或者 没有要删除的节点，直接返回NULL。
    if (tree == NULL || z == NULL)
        return NULL;
    
    if (z->value < tree->value) {       // 待删除的节点在"tree的左子树"中
        tree->left = deleteAVLTree(tree->left, z);
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (heightAVLTree(tree->right) - heightAVLTree(tree->left) == 2) {
            Node *r =  tree->right;
            if (heightAVLTree(r->left) > heightAVLTree(r->right))
                tree = rotationRL(tree);
            else
                tree = rotationRR(tree);
        }
    } else if (z->value > tree->value) { // 待删除的节点在"tree的右子树"中
        tree->right = deleteAVLTree(tree->right, z);
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (heightAVLTree(tree->left) - heightAVLTree(tree->right) == 2) {
            Node *l =  tree->left;
            if (heightAVLTree(l->right) > heightAVLTree(l->left))
                tree = rotationLR(tree);
            else
                tree = rotationLL(tree);
        }
    } else {    // tree是对应要删除的节点。
        // tree的左右孩子都非空
        if ((tree->left) && (tree->right)) {
            if (heightAVLTree(tree->left) > heightAVLTree(tree->right)) {
                // 如果tree的左子树比右子树高；
                // 则(01)找出tree的左子树中的最大节点
                //   (02)将该最大节点的值赋值给tree。
                //   (03)删除该最大节点。
                // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
                Node *max = maximum(tree->left);
                tree->value = max->value;
                tree->left = deleteAVLTree(tree->left, max);
            } else {
                // 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                // 则(01)找出tree的右子树中的最小节点
                //   (02)将该最小节点的值赋值给tree。
                //   (03)删除该最小节点。
                // 这类似于用"tree的右子树中最小节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
                Node *min = minimum(tree->right);
                tree->value = min->value;
                tree->right = deleteAVLTree(tree->right, min);
            }
        } else {
            Node *tmp = tree;
            tree = tree->left ? tree->left : tree->right;
            free(tmp);
        }
    }
    return tree;
}

void deleteAVLTree(AVLRoot *root, Value value) {
    Node *z;
    if ((z = searchRecursionAVLTree(root, value)) != NULL)
        deleteAVLTree(root->node, z);
}

/*
 * 销毁AVL树
 */
void destroyAVLTree(AVLTree tree) {
    if (tree == NULL)
        return;
    if (tree->left != NULL)
        destroyAVLTree(tree->left);
    if (tree->right != NULL)
        destroyAVLTree(tree->right);
    
    free(tree);
}

void destroyTreeAVLTree(AVLRoot *root) {
    destroyAVLTree(root->node);
}

/*
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
void printAVLTree(AVLTree tree, Value value, int direction) {
    if(tree != NULL) {
        if(direction==0)    // tree是根节点
            printf("%2d is root\n", tree->value);
        else                // tree是分支节点
            printf("%2d is %2d's %6s child\n", tree->value, value, direction==1?"right" : "left");
        printAVLTree(tree->left, tree->value, -1);
        printAVLTree(tree->right,tree->value,  1);
    }
}

void printAVLTree(AVLRoot *root) {
    if (root != NULL && root->node != NULL)
        printAVLTree(root->node, root->node->value, 0);
}
