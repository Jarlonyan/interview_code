
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 给定一个数组a，长度为m，表示m个台阶，第i个台阶上有a[i]个虫子
* 青蛙每次最多跳k个台阶
* 青蛙最多跳n次
* 问题：青蛙最多能吃到多少个虫子
*/


int dp_solve(vector<int>& a, int K, int n) {
    int m = a.size();
    vector<vector<int>> dp(m, vector<int>(n+1, 0));

    for(int j=1; j<=n; j++) {
        for(int i=0; i<m; i++) {
            for(int k=1; k<=K; k++) {
                if(i-k>=0 && i-k<m) {
                    dp[i][j] = max(dp[i][j], dp[i-k][j-1]+a[i]);
                }
            }
        }
    }
    return dp[m-1][n];
}

int main() {
    vector<int> a = {1, 8, 2, 9, 6}; //m个台阶，第i个台阶上有a[i]个虫子
    int K = 2; //青蛙每次最多跳k个台阶
    int n = 3; //青蛙最多跳n次

    int res = dp_solve(a, K, n);

    cout<< res<<endl;
    return 0;
}


