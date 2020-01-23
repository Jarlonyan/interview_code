#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class Iterator{
  public:
    Iterator() : ptr(nullptr) {}
    explicit Iterator(T *p) : ptr(p) {};
    Iterator &operator=(T *p) {
        ptr = p;
        return *this;
    }

    Iterator &operator++(int) {
        ptr = ptr->next[0];
        return *this;
    }

    Iterator operator++(int) {
        Iterator temp = *this;
        ptr = ptr->next[0];
        return temp;
    }

    bool operator != (const Iterator &rhs) const { return ptr!=rhs.ptr;}
    bool operator != (const T *p) const { return ptr!=p; }
    bool operator == (const Iterator &rhs) const { return ptr==rhs.ptr; }
    bool operator == (const T *p) const { return ptr==p; }
    bool operator() const { return ptr!=nullptr; }
    operator T *() const { return ptr; }
    T *operator->() const { return ptr; }
    T &operator*() const { return *ptr; }

  private:
    T *ptr;
};


