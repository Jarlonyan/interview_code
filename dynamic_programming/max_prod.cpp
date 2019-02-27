
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_sub_array_prod(vector<int>& a) {
    int n = a.size();
    int cur_sum = 0, max_sum = INT_MIN;
    for(int i=0; i<n; ++i) {
        if(cur_sum < 0)
            cur_sum = a[i];
        else {
            cur_sum += a[i];
            max_sum = max(max_sum, cur_sum);
        }
    }
    return max_sum;
}

int main() {
    vector<int> a = {0, -2, 3, 5, -1, 2, -8};
    int res = max_sub_array_prod(a);
    cout<< res << endl;
    return 0;
}


