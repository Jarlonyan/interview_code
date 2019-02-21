
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

//挨个遍历元素，若j与j+1逆序，则交换。一遍之后，最大的元素会冒在最右端
void bubble_sort(vector<int>& a) {
    int n = a.size();
    for(int i=0;i<n-1;++i) {
        for(int j=n-1; j>i; --j) {
            if(a[j] < a[j-1])
                swap(a[j], a[j-1]);
        }
        print_vec(a);
    }
}

int main () {
    vector<int> a = {8, 1, 9, 3, 7, 6};
    bubble_sort(a);
    return 0;
}

