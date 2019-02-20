
#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int print_vec(vector<int>& b, vector<int>& a, int depth) {
    int sum = 0;
    for (int i = 0; i < a.size() && i<depth ; i++) {
        cout << a[i] << ", ";
        sum += b[a[i]];
    }
    return sum;
}

int dfs_solve(vector<int>& a, int depth, vector<int>& que,  int v, int& res) {
    if (v >= a.size()-1 || depth>=3) { //深度为n=3, 青蛙最多跳n次
        int sum = print_vec(a, que, depth);
        res = max(sum, res);
        cout << ", res=" << res << endl;
        return 0;
    }

    for(int i=1; i<=2; i++) {
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
    int m = 5;
    vector<int> a={8, 1, 9, 6, 3}, que;
    que.push_back(0);
    int res = 8;
    dfs_solve(a, 1, que, 0, res);
    cout << "res=" << res << endl;
    return 0;
}


