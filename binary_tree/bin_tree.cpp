
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : data(x), left(NULL), right(NULL) {}
};

// 创建一颗二叉树,其中A~Z字符代表树的数据,用'#'表示空树
TreeNode* create_bin_tree(string seq, int &pos) { //先序递归构建二叉树
    if (pos >= seq.length()) {
        return NULL;
    }
    else if (seq[pos] == '#') {
        pos++;
        return NULL;
    }
    else {
        TreeNode* T = new TreeNode(seq[pos++]);
        T->left = create_bin_tree(seq, pos);
        T->right = create_bin_tree(seq, pos);
        return T;
    } 
}

void in_order_bin_tree(TreeNode* T) {
    if(T) {
        in_order_bin_tree(T->left);
        cout<< T->data << " ";
        in_order_bin_tree(T->right);
    }
}

void destroy_bin_tree(TreeNode* T) {
    if (T != NULL) {
        destroy_bin_tree(T->left);
        destroy_bin_tree(T->right);
        delete T;
    }
}

int main() {
    string str_seq = "ABC##DE#G##F###";
    int idx = 0;
    TreeNode *T = create_bin_tree(str_seq, idx);
    in_order_bin_tree(T);
    cout<<endl;

    destroy_bin_tree(T);
    return 0;
}


