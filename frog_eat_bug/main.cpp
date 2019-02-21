
#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int print_vec(vector<int>& a, vector<int>& que, int depth) {
    int sum = 0;
    for (int i = 0; i < que.size() && i < depth; ++i) {
        cout << que[i] << ", ";
        sum += a[que[i]];
    }
    return sum;
}

int dfs_solve(vector<int>& a, int depth, vector<int>& que,  int v, int& res) {
    if (v >= int(a.size()-1) || depth >= 3) { //深度为n=3, 青蛙最多跳n次
        int sum = print_vec(a, que, depth);
        res = max(sum, res);
        cout << " sum=" << sum << endl;
        return 0;
    }
    for(int i = 1; i <= 2; ++i) {
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
    vector<int> a={1, 8, 2, 9, 6}, que;
    int res = 0;
    dfs_solve(a, 0, que, -1, res);
    cout << "res=" << res << endl;
    return 0;
}


