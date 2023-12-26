//
// Created by root on 12/10/23.
//

#include "A.hpp"
#include "B.hpp"

int main(){
    A a;
    B b;

    A::send(&b); // Envoit à "b" 5
    B::send(&a); // Envoit à "a" 10

    std::cout << "I = " << a.getI() << std::endl;
    std::cout << "J = " << b.getJ() << std::endl;

    return 0;
}