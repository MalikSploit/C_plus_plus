//
// Created by root on 12/6/23.
//

#include "Mere.hpp"

int Mere::nombre = 0;

Mere::Mere(std::string nom) : nom(std::move(nom)) {
    nombre++;
}
Mere::~Mere()
{
        std::cout << "Destruction de Mere: " << nom << std::endl;
}

int Mere::getCompteur() {
    return nombre;
}

std::string Mere::getName() {
    return nom;
}

void Mere::afficher() {
    std::cout << "Mere : " << getName() << std::endl;
}



