
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
* 题目：如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：(n >= 3)
* 对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
* 给定一个严格递增的正整数数组形成序列，找到 A 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。
* 例如， [3, 5, 8, 13] 是 [3, 4, 5, 6, 7, 8, 13, 16] 的一个子序列）
*
* 
* 思路：设 dp[i,j] 是结束在 [i,j] 的最长路径。那么 如果 (i,j) 和 (j,k) 是连通的，
* dp[j,k]=dp[i,j]+1。由于 i 由 A.index(A[k] - A[j]) 唯一确定，
* 所以这是有效的：我们在 i 潜在时检查每组 j < k，并相应地更新 dp[j,k]
*/


int dp_solve(vector<int>& a) {
    int n = a.size();
    unordered_map<int, int> index;
    for (int i = 0; i < n; ++i)
        index[a[i]] = i;

    unordered_map<int, int> longest;
    int res = 0;
    for (int k = 0; k < N; ++k) {
        for (int j = 0; j < k; ++j) {
            if (a[k] - a[j] < a[j] && index.count(a[k] - a[j])) {
                int i = index[a[k] - a[j]];
                longest[j * n + k] = longest[i * n + j] + 1;
                res = max(res, dp[j * n + k] + 2);
            }
        }
    }
    return res >= 3 ? res : 0;
}

int main() {
    vector<int> a = {3, 4, 5, 6, 7, 8, 13, 16};
    
    return 0;
}


