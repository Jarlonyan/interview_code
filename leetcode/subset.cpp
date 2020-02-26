
#include <iostream>
#include <vector>
#include <algorithm>
#include "common.h"
using namespace std;

void subset(vector<int> a, vector<int> temp, int index) {
    if (index>=a.size()) {
        print_vec(temp);
        return;
    }
    subset(a, temp, index+1);
    temp.push_back(a[index]);
    subset(a, temp, index+1);
}

int  main() {
    vector<int> a = {3,4,5,6};
    vector<int> temp;
    int index = 0;

    subset(a, temp, index);
    return 0;
}


