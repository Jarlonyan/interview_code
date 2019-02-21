
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
    int len = high - low+1, idx = 0, i=low, j=mid+1;
    vector<int> temp(len, 0);
    while(i<=mid && j<=high) {
        temp[idx++] = a[i] <= a[j] ? a[i++]: a[j++];
    }
    while(i <= mid) {
        temp[idx++] = a[i++];
    }
    while(j <= high) {
        temp[idx++] = a[j++];
    }
    for(int k=0; k<len; ++k) {
        a[low++] = temp[k];
    }
}

void merge_sort(vector<int>& a, int low, int high) {
    if(low==high){
        return;
    }
    int mid = (low+high)/2;
    merge_2_array(a, low, mid, mid);
    merge_2_array(a, low, );
}


int main () {
    vector<int> a = {8, 1, 9, 3, 7, 6};
    merge_sort(a);
    return 0;
}

