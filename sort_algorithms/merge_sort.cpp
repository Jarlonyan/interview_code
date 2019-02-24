
#include <vector>
#include <iostream>
using namespace std;

void print_vec(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

void merge_2_array(vector<int>& a, int low, int mid, int high) {
    int n = high-low+1, idx = 0, i=low, j=mid+1;
    vector<int> temp(n, 0);
    while(i <= mid && j <= high) {
        temp[idx++] = a[i] < a[j] ? a[i++] : a[j++];
    }
    while(i <= mid) {
        temp[idx++] = a[i++];
    }
    while(j <= high) {
        temp[idx++] = a[j++];
    }
    copy(temp.begin(), temp.end(), a.begin()+low);
    print_vec(a);
}

void merge_sort(vector<int>& a, int low, int high) {
    if(low == high){
        return;
    }
    int mid = (low+high)/2;
    merge_sort(a, low, mid);    //左边有序
    merge_sort(a, mid+1, high); //右边有序
    merge_2_array(a, low, mid, high); //合并有序的两个数组
}


int main () {
    vector<int> a = {8, 1, 9, 3, 7, 6};
    merge_sort(a, 0, a.size()-1);
    cout<<"res=";
    print_vec(a);
    return 0;
}

