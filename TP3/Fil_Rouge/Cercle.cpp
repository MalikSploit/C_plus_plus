//
// Created by root on 11/30/23.
//

#include "Cercle.hpp"

Cercle::Cercle(int cx, int cy, int r) : Forme(cx, cy), rayon(r), ordre(0) {}

void Cercle::setOrdre(int ord) {
    ordre = ord;
}

std::string Cercle::toString() const {
    std::stringstream ss;
    ss << "Cercle(center: [" << point.getX() << ", " << point.getY() << "], rayon: " << rayon << ", ordre: " << ordre << ")";
    return ss.str();
}

