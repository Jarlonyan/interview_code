
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
    vector<vector<int>> dp(m, vector<int>(n+1, 0)); //dp[i][j]表示当前跳j步
    //init dp, 第一跳的结果
    for(int i=0; i<K; i++) {
        dp[i][1] = a[i];
    }

    for(int i=1; i<m; i++) {
        for(int j=2; j<=n; j++) {
            for(int k=1; k<=K; k++) {
                if(i-k>=0 && i-k<m) {
                    dp[i][j] = max(dp[i][j], dp[i-k][j-1]+a[i]);
                }
            }
        }
    }

    // find res
    int res = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<=n;j++){
            res = max(res, dp[i][j]);
        }
    }

    return res;
}

int main() {
    vector<int> a= {1, 8, 9, 5, 1, 100, 1, 1}; //m个台阶，第i个台阶上有a[i]个虫子
    int K = 2; //青蛙每次最多跳k个台阶
    int n = 3; //青蛙最多跳n次

    int res = dp_solve(a, K, n);

    cout<< res<<endl;
    return 0;
}


