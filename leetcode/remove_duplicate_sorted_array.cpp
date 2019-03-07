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

/* 解法:设置两个指针,i快指针用于遍历,idx慢指针指向当前没有重复序列的最后一个元素
        如果a[i]!=a[idx],那么idx右移一个位置(到了一个废弃位置)，然后a[idx]=a[i]
        如果a[i]==a[idx],那么idx不动，i继续循环
*/
void remove_duplicates(vector<int>& a) {
    int n = a.size();
    int idx=0;
    for(int i=1; i<n; ++i) {
        if(a[i] != a[idx]) {
            idx++;
            a[idx] = a[i];
        }
    }
    a.resize(idx+1); //0~idx才是最终的解，其余的删除
}

int main() {
    vector<int> a = {1, 1, 1, 2, 5, 6, 6};
    print_vec(a);
    remove_duplicates(a);
    print_vec(a);
    return 0;
}


