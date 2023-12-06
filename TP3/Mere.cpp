//
// Created by root on 12/6/23.
//

#include "../TP2/Bavarde.hpp"
#include "Mere.hpp"

Mere::Mere() {
    std::cout << "Je suis la mere" << std::endl;
    nombre++;
}
Mere::~Mere()
{
        std::cout << "Clean done" << std::endl;
}
