#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 题目：remove duplicate from sorted array
* 从一个给定的排序数组中删除重复元素
* example: a=[1,1,1,2,5,6,6]
*/

void print_vec(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

int remove_duplicates(vector<int>& a) {
    int n = a.size();
    int idx=0; //idx记录最终解的最后一个元素
    for(int i=1; i<n; ++i) {
        if(a[i] == a[idx]) {
            continue;
        }
        else {
            idx++;
            a[idx] = a[i];
        }
    }
    return idx;
}



int main() {
    vector<int> a = {1, 1, 1, 2, 5, 6, 6};
    print_vec(a);
    int res = remove_duplicates(a);
    cout<< res <<endl;
    print_vec(a);
    return 0;
}


