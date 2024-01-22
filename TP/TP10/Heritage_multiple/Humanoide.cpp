//
// Created by root on 1/11/24.
//

#include "Humanoide.hpp"

Humanoide::Humanoide(const std::string &nom, const std::string& type, Genre genre, int age) : Humain(nom, genre, age), Machine(type, 3, 3) {}
