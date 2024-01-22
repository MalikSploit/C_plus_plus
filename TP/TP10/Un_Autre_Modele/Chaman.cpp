//
// Created by root on 1/11/24.
//

#include "Chaman.hpp"

Chaman::Chaman(std::string nom) : Elfe(nom) {}

void Chaman::ensorceler() {
std::cout << nom << " the Chaman is casting magic silently!\n";
}