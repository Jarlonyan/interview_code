

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_vec(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

//挨个遍历元素，选择其右边最小的数与其交换
void heap_sort(vector<int>& a) {
    int n = a.size();
    for(int i = 0; i < n-1; ++i) {
        int idx_min = i+1;
        for(int j = idx_min; j < n; ++j) {
            if(a[j] < a[idx_min])
                idx_min = j;
        }
        if(a[idx_min] < a[i])
            swap(a[i], a[idx_min]);
        print_vec(a);
    }
}

int main() {
    vector<int> a = {8, 1, 9, 3, 7, 6};
    select_sort(a);
    return 0;
}

