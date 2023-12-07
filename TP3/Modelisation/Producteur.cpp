//
// Created by root on 12/6/23.
//

#include "Producteur.hpp"

int Producteur::getTravail() const{
    return travail;
}


Producteur::Producteur(){
    std::cout << "Construction Done" << std::endl;
}

Producteur::~Producteur() = default;