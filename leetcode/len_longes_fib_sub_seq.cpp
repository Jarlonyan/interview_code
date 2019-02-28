
//参考：https://leetcode-cn.com/articles/length-of-longest-fibonacci-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// a={2, 3, 5, 6, 8, 9, 13, 14}
//    0, 1, 2, 3, 4, 5,  6,  7
//    dp[i][k]是结束在[i,k]的最长路径
//    dp[i][k] = dp[i][j] + 1
//   dp[1,2]=3, dp[1,3]=0, dp[2,3]=0, 

int len_longes_fib_sub_seq(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, 1));

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(a[i]+a[j]==a[k]) {

            }
        }
    }

    return 0;
}


int main() {
    vector<int> a = {2, 3, 5, 6, 8, 9, 13, 14};


    return 0;
}


