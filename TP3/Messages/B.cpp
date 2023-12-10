//
// Created by root on 12/10/23.
//

#include "B.hpp"
#include "A.hpp"

B::B() : j(0){}

void B::send(A* a){
    const int value = 10;
    a->exec(value);
}

void B::exec(int nombre) {
    j += nombre;
}

int B::getJ() const{
    return j;
}
