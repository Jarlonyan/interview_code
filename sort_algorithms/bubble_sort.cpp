
#include <vector>
#include <iostream>
#include <algorithm>
#include "common.h"
using namespace std;

//冒泡排序：挨个遍历元素，若j与j+1逆序，则交换。一遍之后，最大的元素会冒在最右端
void bubble_sort(vector<int>& a) {
    int n = a.size();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n-1; ++j) {
            if(a[j+1] < a[j])
                swap(a[j+1], a[j]);
        }
        print_vec(a);
    }
}

int main () {
    vector<int> a = {8, 1, 9, 3, 7, 6};
    bubble_sort(a);
    return 0;
}

