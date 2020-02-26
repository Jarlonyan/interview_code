#include <vector>
#include <iostream>

#ifndef _COMMON_H 
#define _COMMON_H 

void print_vec(const std::vector<int>& a) {
    int n = a.size();
    std::cout << "[";
    if (n == 0) {
        std::cout << " ]" << std::endl;
        return;
    }

    for (int i = 0; i < n-1; i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << a[n-1] << "]"<< std::endl;
}

#endif
