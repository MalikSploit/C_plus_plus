//
// Created by root on 11/30/23.
//

#include "Cercle.hpp"

Cercle::Cercle(int cx, int cy, int w, int h) : x(cx), y(cy), ordre(0)
{
    rayon = std::min(w, h) / 2;
}

std::string Cercle::toString() const {
    return "CERCLE " + std::to_string(x) + " " + std::to_string(y)  + " " + std::to_string(rayon);
}