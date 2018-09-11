//
//  RBTree.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/5.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "RBTree.hpp"

#include <stdlib.h>

RBTreeNode *parentRBTreeNode(RBTreeNode *node) { return node->parent; }
NodeColor colorRBTreeNode(RBTreeNode *node) { return node->color; }
bool isRedRBTreeNode(RBTreeNode *node) { return node->color == nodeColorRed; }
bool isBlackRBTreeNode(RBTreeNode *node) { return node->color == nodeColorBlack; }
void setRedRBTreeNode(RBTreeNode *node) { node->color = nodeColorRed; }
void setBlackRBTreeNode(RBTreeNode *node) { node->color = nodeColorBlack; }
void setParentRBTreeNode(RBTreeNode *node, RBTreeNode *parant) { node->parent = parant; }
void setColorRBTreeNode(RBTreeNode *node, NodeColor color) { node->color = color; }

/*
 * 创建红黑树，返回"红黑树的根"
 */
RBRoot* createRBTree() {
    RBRoot *root = (RBRoot *)malloc(sizeof(RBRoot));
    root->node = NULL;
    return root;
}

/*
 * 前序遍历"红黑树"
 */
static void preorder(RBTree tree) {
    if(tree != NULL) {
        printf("%d ", tree->value);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void preorderRBTree(RBRoot *root) {
    if (root)
        preorder(root->node);
}

/*
 * 中序遍历"红黑树"
 */
static void inorder(RBTree tree) {
    if(tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->value);
        inorder(tree->right);
    }
}

void inorderRBTree(RBRoot *root) {
    if (root)
        inorder(root->node);
}

/*
 * 后序遍历"红黑树"
 */
static void postorder(RBTree tree) {
    if(tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->value);
    }
}

void postorderRBTree(RBRoot *root) {
    if (root)
        postorder(root->node);
}

/*
 * (递归实现)查找"红黑树x"中键值为key的节点
 */
static Node* search(RBTree x, Value value) {
    if (x == NULL || x->value == value)
        return x;
    
    if (value < x->value)
        return search(x->left, value);
    else
        return search(x->right, value);
}

int searchRecursionRBTree(RBRoot *root, Value value) {
    if (root)
        return search(root->node, value) ? 0 : -1;
    // root 非法
    return -1;
}

/*
 * (非递归实现)查找"红黑树x"中键值为key的节点
 */
static Node* iterative_search(RBTree x, Value value) {
    while ((x != NULL) && (x->value != value)) {
        if (value < x->value)
            x = x->left;
        else
            x = x->right;
    }
    
    return x;
}

int searchIterativeRBTree(RBRoot *root, Value value) {
    if (root)
        return iterative_search(root->node, value) ? 0 : -1;
    // root 非法
    return -1;
}

/*
 * 查找最小结点：返回tree为根结点的红黑树的最小结点。
 */
static Node* minimum(RBTree tree) {
    if (tree == NULL)
        return NULL;
    
    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

int minimumRBTree(RBRoot *root, int *val) {
    if (root == NULL) {
        return -1;
    }
    
    Node *node = minimum(root->node);
    
    if (node == NULL)
        return -1;
    
    *val = node->value;
    return 0;
}

/*
 * 查找最大结点：返回tree为根结点的红黑树的最大结点。
 */
static Node* maximum(RBTree tree) {
    if (tree == NULL)
        return NULL;
    
    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

int maximumRBTree(RBRoot *root, int *val) {
    if (root == NULL) {
        return -1;
    }
    
    Node *node = maximum(root->node);
    
    if (node == NULL)
        return -1;
    
    *val = node->value;
    return 0;
}

/*
 * 找结点(x)的后继结点。即，查找"红黑树中数据值大于该结点"的"最小结点"。
 */
static Node* successorRBTree(RBTree x) {
    // 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
    if (x->right != NULL)
        return minimum(x->right);
    
    // 如果x没有右孩子。则x有以下两种可能：
    // (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
    // (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
    Node* y = x->parent;
    while ((y!=NULL) && (x==y->right)) {
        x = y;
        y = y->parent;
    }
    return y;
}

/*
 * 找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
 */
static Node* predecessorRBTree(RBTree x) {
    // 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
    if (x->left != NULL)
        return maximum(x->left);
    
    // 如果x没有左孩子。则x有以下两种可能：
    // (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
    // (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
    Node* y = x->parent;
    while ((y!=NULL) && (x==y->left)) {
        x = y;
        y = y->parent;
    }
    return y;
}

/*
 * 对红黑树的节点(x)进行左旋转
 *
 * 左旋示意图(对节点x进行左旋)：
 *      px                             px
 *     /                              /
 *    x                              y
 *   / \      --(左旋)-->            / \                #
 *  lx  y                           x  ry
 *     / \                         / \
 *    ly  ry                      lx  ly
 *
 *
 */
static void rotateLeftRBTree(RBRoot *root, Node *x) {
    // 设置x的右孩子为y
    Node *y = x->right;
    
    // 将 “y的左孩子” 设为 “x的右孩子”；
    // 如果y的左孩子非空，将 “x” 设为 “y的左孩子的父亲”
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    
    // 将 “x的父亲” 设为 “y的父亲”
    y->parent = x->parent;
    
    if (x->parent == NULL) {
        //tree = y;            // 如果 “x的父亲” 是空节点，则将y设为根节点
        root->node = y;            // 如果 “x的父亲” 是空节点，则将y设为根节点
    } else {
        if (x->parent->left == x)
            x->parent->left = y;    // 如果 x是它父节点的左孩子，则将y设为“x的父节点的左孩子”
        else
            x->parent->right = y;    // 如果 x是它父节点的左孩子，则将y设为“x的父节点的左孩子”
    }
    
    // 将 “x” 设为 “y的左孩子”
    y->left = x;
    // 将 “x的父节点” 设为 “y”
    x->parent = y;
}

/*
 * 对红黑树的节点(y)进行右旋转
 *
 * 右旋示意图(对节点y进行左旋)：
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(右旋)-->            /  \                     #
 *        x   ry                           lx   y
 *       / \                                   / \                   #
 *      lx  rx                                rx  ry
 *
 */
static void rotateRightRBTree(RBRoot *root, Node *y) {
    // 设置x是当前节点的左孩子。
    Node *x = y->left;
    
    // 将 “x的右孩子” 设为 “y的左孩子”；
    // 如果"x的右孩子"不为空的话，将 “y” 设为 “x的右孩子的父亲”
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    
    // 将 “y的父亲” 设为 “x的父亲”
    x->parent = y->parent;
    
    if (y->parent == NULL) {
        //tree = x;            // 如果 “y的父亲” 是空节点，则将x设为根节点
        root->node = x;            // 如果 “y的父亲” 是空节点，则将x设为根节点
    } else {
        if (y == y->parent->right)
            y->parent->right = x;    // 如果 y是它父节点的右孩子，则将x设为“y的父节点的右孩子”
        else
            y->parent->left = x;    // (y是它父节点的左孩子) 将x设为“x的父节点的左孩子”
    }
    
    // 将 “y” 设为 “x的右孩子”
    x->right = y;
    
    // 将 “y的父节点” 设为 “x”
    y->parent = x;
}

/*
 * 红黑树插入修正函数
 *
 * 在向红黑树中插入节点之后(失去平衡)，再调用该函数；
 * 目的是将它重新塑造成一颗红黑树。
 *
 * 参数说明：
 *     root 红黑树的根
 *     node 插入的结点        // 对应《算法导论》中的z
 */
static void fixupInsertRBTree(RBRoot *root, Node *node) {
    Node *parent, *gparent;
    
    // 若“父节点存在，并且父节点的颜色是红色”
    while ((parent = parentRBTreeNode(node)) && isRedRBTreeNode(parent)) {
        gparent = parentRBTreeNode(parent);
        
        //若“父节点”是“祖父节点的左孩子”
        if (parent == gparent->left) {
            // Case 1条件：叔叔节点是红色
            {
                Node *uncle = gparent->right;
                if (uncle && isRedRBTreeNode(uncle)) {
                    setBlackRBTreeNode(uncle);
                    setBlackRBTreeNode(parent);
                    setRedRBTreeNode(gparent);
                    node = gparent;
                    continue;
                }
            }
            
            // Case 2条件：叔叔是黑色，且当前节点是右孩子
            if (parent->right == node) {
                Node *tmp;
                rotateLeftRBTree(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            
            // Case 3条件：叔叔是黑色，且当前节点是左孩子。
            setBlackRBTreeNode(parent);
            setRedRBTreeNode(gparent);
            rotateRightRBTree(root, gparent);
        } else { //若“z的父节点”是“z的祖父节点的右孩子”
            // Case 1条件：叔叔节点是红色
            {
                Node *uncle = gparent->left;
                if (uncle && isRedRBTreeNode(uncle)) {
                    setBlackRBTreeNode(uncle);
                    setBlackRBTreeNode(parent);
                    setRedRBTreeNode(gparent);
                    node = gparent;
                    continue;
                }
            }
            
            // Case 2条件：叔叔是黑色，且当前节点是左孩子
            if (parent->left == node) {
                Node *tmp;
                rotateRightRBTree(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            
            // Case 3条件：叔叔是黑色，且当前节点是右孩子。
            setBlackRBTreeNode(parent);
            setRedRBTreeNode(gparent);
            rotateLeftRBTree(root, gparent);
        }
    }
    
    // 将根节点设为黑色
    setBlackRBTreeNode(root->node);
}

/*
 * 添加节点：将节点(node)插入到红黑树中
 *
 * 参数说明：
 *     root 红黑树的根
 *     node 插入的结点        // 对应《算法导论》中的z
 */
static void insertRBTree(RBRoot *root, Node *node) {
    Node *y = NULL;
    Node *x = root->node;
    
    // 1. 将红黑树当作一颗二叉查找树，将节点添加到二叉查找树中。
    while (x != NULL) {
        y = x;
        if (node->value < x->value)
            x = x->left;
        else
            x = x->right;
    }
    setParentRBTreeNode(node, y);
    
    if (y != NULL) {
        if (node->value < y->value)
            y->left = node;                // 情况2：若“node所包含的值” < “y所包含的值”，则将node设为“y的左孩子”
        else
            y->right = node;            // 情况3：(“node所包含的值” >= “y所包含的值”)将node设为“y的右孩子”
    } else {
        root->node = node;                // 情况1：若y是空节点，则将node设为根
    }
    
    // 2. 设置节点的颜色为红色
    node->color = nodeColorRed;
    
    // 3. 将它重新修正为一颗二叉查找树
    fixupInsertRBTree(root, node);
}

/*
 * 创建结点
 *
 * 参数说明：
 *     key 是键值。
 *     parent 是父结点。
 *     left 是左孩子。
 *     right 是右孩子。
 */
static Node* createNodeRBTree(Value value, Node *parent, Node *left, Node* right) {
    Node* p;
    
    if ((p = (Node *)malloc(sizeof(Node))) == NULL)
        return NULL;
    p->value = value;
    p->left = left;
    p->right = right;
    p->parent = parent;
    p->color = nodeColorBlack; // 默认为黑色
    
    return p;
}

/*
 * 新建结点(节点键值为key)，并将其插入到红黑树中
 *
 * 参数说明：
 *     root 红黑树的根
 *     key 插入结点的键值
 * 返回值：
 *     0，插入成功
 *     -1，插入失败
 */
int insertRBTree(RBRoot *root, Value value) {
    Node *node;    // 新建结点
    
    // 不允许插入相同键值的节点。
    // (若想允许插入相同键值的节点，注释掉下面两句话即可！)
    if (search(root->node, value) != NULL)
        return -1;
    
    // 如果新建结点失败，则返回。
    if ((node=createNodeRBTree(value, NULL, NULL, NULL)) == NULL)
        return -1;
    
    insertRBTree(root, node);
    
    return 0;
}

/*
 * 红黑树删除修正函数
 *
 * 在从红黑树中删除插入节点之后(红黑树失去平衡)，再调用该函数；
 * 目的是将它重新塑造成一颗红黑树。
 *
 * 参数说明：
 *     root 红黑树的根
 *     node 待修正的节点
 */
static void fixupDeleteRBTree(RBRoot *root, Node *node, Node *parent) {
    Node *other;
    
    while ((!node || isBlackRBTreeNode(node)) && node != root->node) {
        if (parent->left == node) {
            other = parent->right;
            if (isRedRBTreeNode(other)) {
                // Case 1: x的兄弟w是红色的
                setBlackRBTreeNode(other);
                setRedRBTreeNode(parent);
                rotateLeftRBTree(root, parent);
                other = parent->right;
            }
            if ((!other->left || isBlackRBTreeNode(other->left)) &&
                (!other->right || isBlackRBTreeNode(other->right))) {
                // Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的
                setRedRBTreeNode(other);
                node = parent;
                parent = parentRBTreeNode(node);
            } else {
                if (!other->right || isBlackRBTreeNode(other->right)) {
                    // Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。
                    setBlackRBTreeNode(other->left);
                    setRedRBTreeNode(other);
                    rotateRightRBTree(root, other);
                    other = parent->right;
                }
                // Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
                setColorRBTreeNode(other, colorRBTreeNode(parent));
                setBlackRBTreeNode(parent);
                setBlackRBTreeNode(other->right);
                rotateLeftRBTree(root, parent);
                node = root->node;
                break;
            }
        } else {
            other = parent->left;
            if (isRedRBTreeNode(other)) {
                // Case 1: x的兄弟w是红色的
                setBlackRBTreeNode(other);
                setRedRBTreeNode(parent);
                rotateRightRBTree(root, parent);
                other = parent->left;
            }
            if ((!other->left || isBlackRBTreeNode(other->left)) &&
                (!other->right || isBlackRBTreeNode(other->right))) {
                // Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的
                setRedRBTreeNode(other);
                node = parent;
                parent = parentRBTreeNode(node);
            } else {
                if (!other->left || isBlackRBTreeNode(other->left)) {
                    // Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。
                    setBlackRBTreeNode(other->right);
                    setRedRBTreeNode(other);
                    rotateLeftRBTree(root, other);
                    other = parent->left;
                }
                // Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
                setColorRBTreeNode(other, colorRBTreeNode(parent));
                setBlackRBTreeNode(parent);
                setBlackRBTreeNode(other->left);
                rotateRightRBTree(root, parent);
                node = root->node;
                break;
            }
        }
    }
    if (node)
        setBlackRBTreeNode(node);
}

/*
 * 删除结点
 *
 * 参数说明：
 *     tree 红黑树的根结点
 *     node 删除的结点
 */
void deleteRBTree(RBRoot *root, Node *node) {
    Node *child, *parent;
    int color;
    
    // 被删除节点的"左右孩子都不为空"的情况。
    if ( (node->left!=NULL) && (node->right!=NULL) ) {
        // 被删节点的后继节点。(称为"取代节点")
        // 用它来取代"被删节点"的位置，然后再将"被删节点"去掉。
    
        // 获取后继节点  这里的 后继节点取的是右孩子的最左节点(也就是说是这颗子树的最小值)
        // 具体查看 查找二叉树 的删除操作
        Node *replace = node->right;
        while (replace->left != NULL)
            replace = replace->left;
        
        // "node节点"不是根节点(只有根节点不存在父节点)
        if (parentRBTreeNode(node)) {
            if (parentRBTreeNode(node)->left == node)
                parentRBTreeNode(node)->left = replace;
            else
                parentRBTreeNode(node)->right = replace;
        }
        else
            // "node节点"是根节点，更新根节点。
            root->node = replace;
        
        // child是"取代节点"的右孩子，也是需要"调整的节点"。
        // "取代节点"肯定不存在左孩子！因为它是一个后继节点。
        child = replace->right;
        parent = parentRBTreeNode(replace);
        // 保存"取代节点"的颜色
        color = colorRBTreeNode(replace);
        
        // "被删除节点"是"它的后继节点的父节点"
        if (parent == node) {
            parent = replace;
        } else {
            // child不为空
            if (child)
                setParentRBTreeNode(child, parent);
            parent->left = child;
            
            replace->right = node->right;
            setParentRBTreeNode(node->right, replace);
        }
        
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;
        
        if (color == nodeColorBlack)
            fixupDeleteRBTree(root, child, parent);
        free(node);
        
        return ;
    }
    
    if (node->left !=NULL)
        child = node->left;
    else
        child = node->right;
    
    parent = node->parent;
    // 保存"取代节点"的颜色
    color = node->color;
    
    if (child)
        child->parent = parent;
    
    // "node节点"不是根节点
    if (parent) {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }
    else
        root->node = child;
    
    if (color == nodeColorBlack)
        fixupDeleteRBTree(root, child, parent);
    free(node);
}

/*
 * 删除键值为key的结点
 *
 * 参数说明：
 *     tree 红黑树的根结点
 *     key 键值
 */
void deleteRBTree(RBRoot *root, Value value) {
    Node *z;
    
    if ((z = search(root->node, value)) != NULL)
        deleteRBTree(root, z);
}

/*
 * 销毁红黑树
 */
static void destroyRBTree(RBTree tree) {
    if (tree==NULL)
        return ;
    
    if (tree->left != NULL)
        destroyRBTree(tree->left);
    if (tree->right != NULL)
        destroyRBTree(tree->right);
    
    free(tree);
}

void destroyRBTree(RBRoot *root) {
    if (root != NULL)
        destroyRBTree(root->node);
    
    free(root);
}

/*
 * 打印"红黑树"
 *
 * tree       -- 红黑树的节点
 * key        -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
static void printRBTree(RBTree tree, Value key, int direction) {
    if(tree != NULL) {
        if(direction==0)    // tree是根节点
            printf("%2d(B) is root\n", tree->value);
        else                // tree是分支节点
            printf("%2d(%s) is %2d's %6s child\n", tree->value, isRedRBTreeNode(tree)?"R":"B", key, direction==1?"right" : "left");
        
        printRBTree(tree->left, tree->value, -1);
        printRBTree(tree->right,tree->value,  1);
    }
}

void printRBTree(RBRoot *root) {
    if (root!=NULL && root->node!=NULL)
        printRBTree(root->node, root->node->value, 0);
}
