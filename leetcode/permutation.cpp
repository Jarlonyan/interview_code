
#include <iostream>
#include <vector>
#include <algorithm>
#include "common.h"
using namespace std;

void permutation(vector<int>& a, int left, int right) {
    if(left==right){
        print_vec(a);
        return;
    }
    for(int i=left; i<right; i++) {
        swap(a[left], a[i]);
        permutation(a, left+1, right);
        swap(a[left], a[i]);
    }
}

int  main() {
    vector<int> a = {3, 4, 5, 6};
    permutation(a, 0, a.size());
    return 0;
}


