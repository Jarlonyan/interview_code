
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#include "bin_tree.hpp"

// 判断二叉树是否平衡
int judge_balance_bin_tree(TreeNode* T) {
    if (T==NULL) 
        return 0;
    return 1 + get_node_count(T->left) + get_node_count(T->right);
}

// 判断二叉树是否对称
int judge_symmetric_bin_tree(TreeNode* T, int k) {
    if(T==NULL || k<=0) {
        return 0;
    }
    if(T!=NULL && k==1) {
        return 1;
    }
    return get_k_level_count(T->left, k-1) + get_k_level_count(T->right, k-1);
}

int main() {
    string seq = "ABC##DE#G##F###";
    int pos = 0;
    TreeNode *T = create_bin_tree(seq, pos);


    destroy_bin_tree(T);
    return 0;
}
