//
// Created by root on 12/10/23.
//

#include "A.hpp"
#include "B.hpp"

A::A() : i(0){}

void A::send(B* b){
    const int value = 5;
    b->exec(value);
}

void A::exec(int nombre) {
    i += nombre;
}

int A::getI() const {
    return i;
}
