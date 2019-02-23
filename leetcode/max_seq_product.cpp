
#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
* 题目:给定数组，找出连续乘积最大值的子序列
* 
*
*/

vector<int> a = {1, 8, 2, 9, 6}; //m个台阶，第i个台阶上有a[i]个虫子
int k = 2; //青蛙每次最多跳k个台阶
int n = 3; //青蛙最多跳n次

int print_vec(vector<int>& a, vector<int>& que, int depth) {
    int sum = 0;
    for (int i = 0; i < que.size() && i < depth; ++i) {
        cout << que[i] << ", ";
        sum += a[que[i]];
    }
    return sum;
}

int dfs_solve(vector<int>& a, int depth, vector<int>& que,  int v, int& res) {
    if (v >= int(a.size()-1) || depth >= n) { //深度为n=3, 青蛙最多跳n次
        int sum = print_vec(a, que, depth);
        res = max(sum, res);
        cout << " sum=" << sum << endl;
        return 0;
    }

    for(int i = 1; i <= k; ++i) { // 当前节点是v，邻居节点是从v跳1,2,...,k步
        int w = v + i;
        if (w < a.size()) {
            que.push_back(w);
            dfs_solve(a, depth+1, que, w, res);
            que.pop_back();
        }
    }

    return 0;
}

int main() {
    vector<int> que;
    int res = 0;
    dfs_solve(a, 0, que, -1, res); //深度搜索，depth=0； 青蛙刚开始在-1的位置, que用来记录路径
    cout << "res=" << res << endl;
    return 0;
}


