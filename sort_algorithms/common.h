#include <vector>
#include <iostream>

#ifndef _COMMON_H 
#define _COMMON_H 

void print_vec(std::vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}

#endif
