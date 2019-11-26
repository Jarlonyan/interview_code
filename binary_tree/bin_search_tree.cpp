
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
二叉查找树：
(1) 左子树上所有结点的值均小于它的根结点的值;
(2) 右子树上所有结点的值均大于它的根结点的值;
(3) 任意节点的左、右子树也分别为二叉查找树;
(4) 没有键值相等的节点（no duplicate nodes）
https://www.cnblogs.com/skywang12345/p/3576373.html
*/

template <class T>
class BSTNode{
    public:
        T key;            // 关键字(键值)
        BSTNode *left;    // 左孩子
        BSTNode *right;   // 右孩子
        BSTNode *parent;  // 父结点

        BSTNode(T value, BSTNode *parent, BSTNode *pleft, BSTNode *pright) {
            key = value;
            parent = NULL;
            left = pleft;
            right = pright;
        }
};

template <class T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T>* z)
{
    BSTNode<T> *y = NULL;
    BSTNode<T> *x = tree;

    // 查找z的插入位置
    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y==NULL)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

int main() {
    vector<int> a = {2,9,1,7,5,6};
    BSTNode<int> *T = NULL;
    

    return 0;
}


