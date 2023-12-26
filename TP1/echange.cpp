//
// Created by root on 11/29/23.
//

#include <iostream>

int main()
{
    int  a = 3;
    int  b = a;
    int& c = a;

    std::cout << a << " " << b << " " << c << std::endl;
    b = 4;
    std::cout << a << " " << b << " " << c << std::endl;
    c = 5;
    std::cout << a << " " << b << " " << c << std::endl;
    a = 6;
    std::cout << a << " " << b << " " << c << std::endl;
}