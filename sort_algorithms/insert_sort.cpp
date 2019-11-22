
#include <vector>
#include <iostream>
#include "common.h"
using namespace std;

//插入排序：挨个遍历元素，将其插入其左边有序数组中
void insert_sort(vector<int>& a) {
    int n = a.size();
    for(int i = 1; i < n; ++i) {
        int temp = a[i], j;
        for(j = i-1; j >= 0; --j) {
            if(temp < a[j])
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = temp;
        print_vec(a);
    }
}

int main() {
    vector<int> a = {8, 1, 9, 3, 7, 6};
    insert_sort(a);
    return 0;
}

