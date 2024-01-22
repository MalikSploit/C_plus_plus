//
// Created by root on 12/10/23.
//

#include <iostream>

class B;

#ifndef C_A_HPP
#define C_A_HPP

class A {
private:
    int i;
public:
    A();
    static void send(B *b);
    void exec(int nombre);
    int getI() const;
};

#endif //C_A_HPP
