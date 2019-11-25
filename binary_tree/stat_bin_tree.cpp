
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#include "bin_tree.hpp"

// 求二叉树第K层的节点个数
int get_k_level_count(TreeNode* T, int k) {
    if(T==NULL || k<=0) {
        return 0;
    }
    if(T!=NULL && k==1) {
        return 1;
    }
    return get_k_level_count(T->left, k-1) + get_k_level_count(T->right, k-1);
}

// 求二叉树第K层的叶子节点个数
int get_k_level_leaf_count(TreeNode *T, int k) {
    if (T==NULL || k<=0) {
        return 0;
    }
    if (T!=NULL && k==1) {
        if (T->left==NULL && T->right==NULL)
            return 1;
        else
            return 0;
    }
    return get_k_level_leaf_count(T->left, k-1) + get_k_level_leaf_count(T->right, k-1);
}

int main() {
    string seq = "ABC##DE#G##F###";
    int pos = 0;
    TreeNode *T = create_bin_tree(seq, pos);

    int ret = 0;
    ret = get_k_level_count(T, 2);
    //ret = get_k_level_leaf_count(T, 2);

    cout<<ret<<endl;

    destroy_bin_tree(T);
    return 0;
}
