
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

void print_vec(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

int partition(vector<int>& a, int low, int high) {
    int pivot = a[low];
    while(low < high) {
        while(low < high && pivot < a[high])
            high--;
        a[low] = a[high];
        while(low < high && a[low] < pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quick_sort(vector<int>& a, int low, int high) {
   if(low < high) {
        int mid = partition(a, low, high);
        print_vec(a);
        quick_sort(a, low, mid-1);
        quick_sort(a, mid+1, high);
   } 
}

void quick_sort_not_recur(vector<int>& a) {
    stack<pair<int,int>> st;
    int low = 0, high = a.size() - 1;
    do{
        int mid = partition(a, low, high);
        print_vec(a);

        if(low < mid-1)
            st.push({low, high-1});
        if(mid+1 < high)
            st.push({mid+1, high});
        
        pair<int,int> x = st.top();
        st.pop();
        low = x.first;
        high = x.second;
        if(st.empty()) //保证栈中最后一个元素也要经过partition操作
            partition(a, low, high); 
    } while(!st.empty());
}

int main () {
    vector<int> a = {8, 1, 9, 3, 7, 6};
    //quick_sort(a, 0, a.size()-1);
    quick_sort_not_recur(a);
    return 0;
}

