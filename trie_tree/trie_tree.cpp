

//https://zhuanlan.zhihu.com/p/34747612


#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TrieNode{
    TrieNode* next[26];
    bool is_word;
    TrieNode() {
        memset(next, NULL, sizeof(next));
        is_word = false;
    }

    ~TrieNode() {
        for(int i=0; i<26; ++i) {
            if(next[i])
                delete next[i];
        }
    }
};


int main() {
    vector<int> a = {1, 3, 5, 7, 8, 9};

    return 0;
}

