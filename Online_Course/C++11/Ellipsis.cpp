//
// Created by malik on 12/28/2023.
//
#include <iostream>
#include <cstdarg>


int sum(int n, ...){
    va_list list;
    va_start(list, n);
    int s = 0;
    for (int i = 0; i < n; i++){
        s += va_arg(list, int);
    }
    va_end(list);
    return s;
}

int main(){
    std::cout << sum(1, 1) << std::endl; //1
    std::cout << sum(2, 1, 2) << std::endl; //3
    std::cout << sum(3, 1, 2, 3) << std::endl; //6
    std::cout << sum(4, 1, 2, 3, 4) << std::endl; //10
    std::cout << sum(5, 1, 2, 3, 4, 5) << std::endl; //15
    return 0;
}