
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
问题引入：给你n个数，有两种操作：1：给第i个数的值增加X? 2：询问区间[a,b]的总和是什么？
概念：线段树是一颗近似的完全二叉树，每个节点代表一个区间，节点的权值是该区间的最小值。
      根节点是整个区间。每个节点的左孩子是该节点所代表的的区间的左半部分，右孩子是右半部分。
      为方便起见，如果区间长度为奇数，则左孩子为较长的半部分。通过线段树，我们可以用O(logn)的时间复杂度完成查询和更新操作。当然，预处理的时间复杂度是O(n)。
说明：一般的线段树上的每一个节点T[a,b]，代表该节点维护了原数列[a, b]区间的信息。
      对于每一个节点他至少有三个信息：左端点，右端点，我们需要维护的信息（在本题中我们维护区间和）。
      由于线段树是一个二叉树，而且是一个平衡二叉树，如果当前结点的编号是i，左端点为L, 右端点为R, 那么左儿子的编号为i*2, 左端点为L, 右端点为(L+R)/2 ; 
      同理右儿子的 编号为 i*2+1，左端点为（L+R)/2  ，右端点为 R。
      如果当前结点的左端点等于右端点，那么该节点就是叶子节点，直接在该节点赋值即可。显然线段树是递归定义的。
存储：线段树的存储可用链表和数组模拟。
https://blog.crazyark.me/posts/segment_tree/
http://blog.sina.com.cn/s/blog_14ecbfd490102wl8u.html
*/

class SegmentTree {
  private:
    int n;
    vector<int> max_val;
    vector<int> to_add;

    void push(int i, int tl, int tr) {
        max_val[i] += to_add[i];
        if (tl != tr-1) {
            to_add[2*i+1] += to_add[i];
            to_add[2*i+2] += to_add[i];
        }
        to_add[i] = 0;
    }

    void add(int i, int tl, int tr, int l, int r, int delta) {
        push(i, tl, tr);
        if (tl >= r || tr <=l) return;
        else if (l <= tl && tr <=r ) {
            to_add[i] += delta;
            push(i, tl, tr);
            return;
        }
        int tm = (tl+tr)/2;
        add(2*i+1, tl, tm, l, r, delta);
        add(2*i+2, tm, tr, l, r, delta);
    }

};

int main() {
    

    return 0;
}
