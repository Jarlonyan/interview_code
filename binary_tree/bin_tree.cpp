
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

/* 题目：将有序数组转成二分查找树
   这道题是二分查找树的题目，要把一个有序数组转换成一颗二分查找树。其实从本质来看，
   如果把一个数组看成一棵树（也就是以中点为根，左右为左右子树，依次下去）数组就等价于
   一个二分查找树。所以如果要构造这棵树，那就是把中间元素转化为根，然后递归构造左右子树。
   所以我们还是用二叉树递归的方法来实现，以根作为返回值，每层递归函数取中间元素，作为当前根和赋上结点值，
   然后左右结点接上左右区间的递归函数返回值。时间复杂度还是一次树遍历O(n)，总的空间复杂度是栈空间O(logn)
   加上结果的空间O(n)，额外空间是O(logn)，总体是O(n)。
*/

TreeNode* sort_array_2_BST(vector<int>& a) {
    int n = a.size();
    if(n == 0) {
        return NULL;
    }
    return helper(a, 0, n-1);
}

TreeNode* helper(vector<int>& a, int left, int right) {
    if(left > right) {
        return NULL;
    }
    int mid = (left+right)/2;
    TreeNode* root = new TreeNode(a[mid]);
    root.left = helper(a, left, mid-1);
    root.right = helper(a, a, mid+1, r);
    return root;
}


int main() {
    return 0;
}


