

#include <vector>
#include <iostream>
#include <algorithm>
#include "common.h"
using namespace std;

// 希尔排序：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序
// 插入排序的优化版:
//     因为插入排序需要一位一位比较，然后放置到正确位置。为了提升比较的跨度，希尔排序将数组按照一定步长分成几个子数组进行排序，通过逐渐减短步长来完成最终排序。
/* 算法步骤:
    计算当前步长，按步长划分子数组
    子数组内插入排序
    步长除以2后继续12两步，直到步长最后变成1
*/

void shell_sort(vector<int> &a) {
    int n = a.size();
    for (int gap = a.size() >> 1; gap > 0; gap >>= 1) { // times
        for (int i = gap; i < n; i++) { // position
            int temp = a[i];

            int j = i - gap;
            for (; j >= 0 && a[j] > temp; j -= gap) {
                a[j + gap] = a[j];
            }

            a[j + gap] = temp;
        }
        print_vec(a);
    }
}

int main() {
    vector<int> a = {8, 1, 9, 3, 7, 6};
    shell_sort(a);
    print_vec(a);
    return 0;
}

