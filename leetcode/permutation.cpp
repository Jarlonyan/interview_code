
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> permutation(vector<int> a) {
    vector<vector<int>> ret;
    int n = a.size();
    for(int i=0; i<n; ++i) {
        swap(a[i], a[j]);

    }

    return ret;
}

int  main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    return 0;
}


