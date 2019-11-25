
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#include "bin_tree.hpp"

vector<vector<char>> level_order_bin_tree(TreeNode* T) {
    vector<vector<char>> ret;
    if (!T) return ret;
    queue<TreeNode*> que;
    que.push(T);
    while (!que.empty()) {
        vector<char> temp;
        int n = que.size();
        while(n--){
            TreeNode* x = que.front(); que.pop();
            if(x->left) que.push(x->left);
            if(x->right) que.push(x->right);
            temp.push_back(x->data);
        }
        ret.push_back(temp);
    }
    return ret;
}

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
