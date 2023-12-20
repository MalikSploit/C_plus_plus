//
// Created by root on 12/20/23.
//
#include <iostream>

const int &max(const int &a, const int &b) {
    return ((a > b) ? a : b);
}

template<typename T>
const T &maximum(const T &a, const T &b){
    return ((a > b) ? a : b);
}

int main(){
    std::cout << maximum(10.5, 20.5) << std::endl;
    //std::cout << maximum(10.5, 20) << std::endl;
    std::cout << maximum(10.5, (double)20);
    return 0;
}