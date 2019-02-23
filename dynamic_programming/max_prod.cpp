
#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sort_array_2_BST(vector<int>& a, int left, int right) {
    if(left > right) {
        return NULL;
    }
    int mid = (left+right)/2;
    TreeNode* root = new TreeNode(a[mid]);
    root->left = helper(a, left, mid-1);
    root->right = helper(a, mid+1, right);
    return root;
}

int main() {
    vector<int> a = {1, 3, 5, 7, 8, 9};
    
    return 0;
}


