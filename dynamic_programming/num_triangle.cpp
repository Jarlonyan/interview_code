
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_sum_num_trie(vector<vector<int>>& a, int n) {
    int dp[100][100] = {1};
    for(int i=n-1; i>=1; --i){
        for(int j=1; j<=i; ++j)
            dp[i][j] = dp[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
    }
    return dp[1][1];
}

int main() {
    vector<vector<int>> a = {
        {9},
        {12, 15},
        {10, 6, 8},
        {2, 18, 9, 5}
    };
    int n = 4;
    int res = max_sum_num_trie(a, n);
    cout<< res << endl;
    return 0;
}


