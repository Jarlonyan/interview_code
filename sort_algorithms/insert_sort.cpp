
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

void insert_sort(vector<int>& a) {
    int n = a.size();
    for(int i = n-1; i >= 0; --i) {
        int temp = a[i];
        int j = i - 1;
        while(j >= 0 && a[i] < a[j]) {
            a[j+1] = a[j];
            --j;
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

