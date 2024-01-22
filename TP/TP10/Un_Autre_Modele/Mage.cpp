//
// Created by root on 1/11/24.
//

#include "Mage.hpp"

Mage::Mage(std::string nom) : Humain(nom) {}

void Mage::ensorceler(){
    std::cout << nom << " the Mage is magic casting by speaking!\n";
}