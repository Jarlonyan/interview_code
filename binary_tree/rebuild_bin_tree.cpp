
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#include "bin_tree.hpp"

/*
二叉树前序遍历序列中，第一个元素总是树的根节点的值。中序遍历序列中，左子树的节点的值位于根节点的值的左边，右子树的节点的值位
于根节点的值的右边。
递归解法：
（1）如果前序遍历为空或中序遍历为空或节点个数小于等于0，返回NULL。
（2）创建根节点。前序遍历的第一个数据就是根节点的数据，在中序遍历中找到根节点的位置，可分别得知左子树和右子树的前序和中序遍
历序列，重建左右子树。
*/



int main() {
    string seq = "39##15##6##";
    int pos = 0;
    TreeNode *T = create_bin_tree(seq, pos);

    auto ret = level_order_bin_tree(T);
    for(int i=0; i<ret.size(); ++i) {
        for(int j=0; j<ret[i].size(); ++j) {
            cout<< ret[i][j] <<",";
        }
        cout<< endl;
    }

    destroy_bin_tree(T);
    return 0;
}
