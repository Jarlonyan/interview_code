
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
        BSTNode(T value) {
            key = value;
            parent = NULL;
            left = NULL;
            right = NULL;
        }
};

template <class T>
void insert(BSTNode<T>* &root, T val) {
    BSTNode<T> *x = new BSTNode<T>(val);
    BSTNode<T> *pre = NULL;
    BSTNode<T> *p = root;

    // 查找val的插入位置
    while (p != NULL) {
        pre = p;
        if (val < p->key)
            p = p->left;
        else
            p = p->right;
    }

    x->parent = pre;
    if (pre==NULL)
        root = x;
    else if (val < pre->key)
        pre->left = x;
    else
        pre->right = x;
}

template <class T>
void pre_order_bin_tree(BSTNode<T>* root) {
    if (root) {
        cout<< root->key << " ";
        pre_order_bin_tree(root->left);
        pre_order_bin_tree(root->right);
    }
}

template <class T>
void destroy(BSTNode<T>* &root) {
    if (root == NULL) return;
    if (root->left)
        destroy(root->left);
    if (root->right)
        destroy(root->right);
    delete root;
    root = NULL;
}

int main() {
    vector<int> a = {2,9,1,7,5,6};
    BSTNode<int> *root = new BSTNode<int>(a[0]);
    for (int i=1; i<a.size(); ++i) {
        insert(root, a[i]);
    }

    pre_order_bin_tree(root);
    cout<<endl;

    destroy(root);
    return 0;
}


