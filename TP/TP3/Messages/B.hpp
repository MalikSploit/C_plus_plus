//
// Created by root on 12/10/23.
//
#include <iostream>

#ifndef C_B_HPP
#define C_B_HPP
class A;

class B {
private:
    int j;
public:
    B();
    static void send(A *a);
    void exec(int nombre);
    int getJ() const;
};

#endif //C_B_HPP
