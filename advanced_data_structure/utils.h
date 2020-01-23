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
    Iterator &operator = (T *p) {
        ptr = p;
        return *this;
    }

    Iterator operation++(int) {
        
    }

};


