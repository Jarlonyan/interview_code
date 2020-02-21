
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

//https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/deque-c-by-he-le-le-le-la-e/
#include "bin_tree.hpp"

// ZigZag方式遍历二叉树，蛇形遍历二叉树
/* 比如：  1
          / \
         2   3
        / \   \
       4   5   6
          / \
         7   8
返回：[
        [1],
        [2,3],
        [4,5,6]
        [7,8]
      ]
*/

vector<vector<char>> zigzag_level_bin_tree(TreeNode* root) {
    vector<vector<char>> ret;
    deque<TreeNode*> deque;
    bool to_left = true;

    if (!root) {
        return ret;
    }
    deque.push_back(root);

    while ( !deque.empty() ) {
        ret.push_back({});
        int n = deque.size();
        for (int i=0; i<n; ++i) {
            TreeNode* cur = NULL;
            if (to_left) {
                cur = deque.back(); deque.pop_back();
            }
            else {
                cur = deque.front(); deque.pop_front();
            }
            ret[ret.size()-1].push_back(cur->data);
            if (to_left) {
                if (cur->right) deque.push_front(cur->right);
                if (cur->left) deque.push_front(cur->left);
            }
            else {
                if (cur->left) deque.push_back(cur->left);
                if (cur->right) deque.push_back(cur->right);
            }
        }
        to_left = !to_left;
    }
    return ret;
}

int main() {
    //string seq = "124##57##8##3#6##";
    string seq = "19##15##6##";
    int pos = 0;
    TreeNode *T = create_bin_tree(seq, pos);

    auto ret = zigzag_level_bin_tree(T);
    for(int i=0; i<ret.size(); ++i) {
        for(int j=0; j<ret[i].size(); ++j) {
            cout<< ret[i][j] <<",";
        }
        cout<< endl;
    }

    //in_order_bin_tree(T);
    //cout<<endl;

    destroy_bin_tree(T);
    return 0;
}
