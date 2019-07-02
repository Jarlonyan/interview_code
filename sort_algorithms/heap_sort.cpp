

#include <vector>
#include <iostream>
#include <algorithm>
#include "common.h"
using namespace std;

void max_heapify(vector<int> &a, int beg, int end)
{
    int curr = beg;
    int child = curr * 2 + 1;
    while (child < end) {
        if (child + 1 < end && a[child] < a[child + 1]) {
            child++;
        }
        if (a[curr] < a[child]) {
            swap(a[child], a[curr]);
            curr = child;
            child = 2 * curr + 1;
        } else {
            break;
        }
    }
}

// 
void heap_sort(vector<int>& a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) { // build max heap
        max_heapify(a, i, a.size() - 1);
    }
    
    for (int i = n - 1; i > 0; i--) { // heap sort
        swap(a[0], a[i]);
        max_heapify(a, 0, i);
        print_vec(a);
    }
}

int main() {
    vector<int> a = {8, 1, 9, 3, 7, 6};
    heap_sort(a);
    return 0;
}

