
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

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
    vector<char> ivec;
    queue<TreeNode*> tree_queue;
    if (NULL == root) {
        return ret;
    }
    return ret; 
}

int main() {
    string seq = "39##15##6##";
    int pos = 0;
    TreeNode *T = create_bin_tree(seq, pos);

    in_order_bin_tree(T);
    cout<<endl;

    destroy_bin_tree(T);
    return 0;
}
