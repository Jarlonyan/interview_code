
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

// ZigZag方式遍历二叉树，即：根->左子->右子->右子的左子->右子的右子->XXX
/* 比如：  3
          / \
         9   1
            / \
           5   6
返回：[
        [3],
        [1,9],
        [5,6]
      ]
*/

vector<vector<char>> zigzag_level_bin_tree(TreeNode* root) {
    vector<vector<char>> ret;
    deque<TreeNode*> deque;
    bool to_right = true;

    if (!root) {
        return ret;
    }
    deque.push_back(root);

    while ( !deque.empty() ) {
        ret.push_back({});
        int n = deque.size();
        for (int i=0; i<n; ++i) {
            TreeNode* cur = NULL;
            if (to_right) {
                cur = deque.front();
                deque.pop_front();
            }
            else {
                cur = deque.back();
                deque.pop_back();
            }
            ret[ret.size()-1].push_back(cur->data);
            if (to_right) {
                if (cur->left) deque.push_back(cur->left);
                if (cur->right) deque.push_back(cur->right);
            }
            else {
                if (cur->right) deque.push_front(cur->right);
                if (cur->left) deque.push_front(cur->left);
            }
        }
        to_right = !to_right;
    }
    return ret;
}

int main() {
    string seq = "39##15##6##";
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
