/*
一个跳表具有以下特征：
1.一个跳表应该有几个层（level）组成；
2.跳表的第一层包含所有的元素；
3.每一层都是一个有序的链表；
4.如果元素x出现在第i层，则所有比i小的层都包含x；
5.第i层的元素通过一个down指针指向下一层拥有相同值的元素；
6.Top指针指向最高层的第一个元素。
https://github.com/guoxiao/skiplist/blob/master/skiplist.hpp
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<typename KeyType, typename ValueType>
struct Node {
    KeyType key;
    ValueType value;
    size_t level;
    Node **next;
    Node(): key(), value(), level(0), next(nullptr) {}
    Node(const Node &) = delete;
    Node &operator=(const Node &) = delete;
};






int main() {

    return 0;
}

