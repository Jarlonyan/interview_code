

/*
实现trie树：
1、实现操作insert插入、 search搜索、startsWith是否存在以某个prefix开头的单词
2、要求插入的字符串中只包含小写字母
3、https://zhuanlan.zhihu.com/p/34747612
*/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

// 字典树
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

class Trie {
  private:
    TrieNode* root;
  public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *p = root;
        for(int i=0; i<(int)word.size(); ++i) {
            if (p->next[word[i]-'a'] == NULL)
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->is_word = true;
    }

    bool search(string word) {
        TrieNode *p = root;
        for (int i=0; i<word.size() && p; ++i) {
            p = p->next[word[i]-'a'];
        }
        return p && p->is_word;
    }

    bool starts_with(string prefix) {
        TrieNode *p = root;
        for(int i=0; i<prefix.size() && p; ++i) {
            p = p->next[prefix[i]-'a'];
        }
        return p;
    }

    ~Trie() {
        delete root;
    }
};




int main() {
    string word = "asdgghaia";
    Trie trie;
    trie.insert(word);
    cout<< trie.starts_with("asdg") <<endl;

    return 0;
}

