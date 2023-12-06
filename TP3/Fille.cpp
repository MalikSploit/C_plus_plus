//
// Created by root on 12/6/23.
//
#include <iostream>
#include "Mere.hpp"

class Fille: public Mere{
public:
    explicit Fille() : Mere() {
        std::cout << "Je suis la fille" << std::endl;
    }
};