//
// Created by root on 11/30/23.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(int x, int y, int w, int h) : Forme(x, y), w(w), h(h), ordre(0) {}

void Rectangle::setOrdre(int nb) {
    this->ordre = nb;
}

std::string Rectangle::toString() const {
    std::stringstream ss;
    ss << "Rectangle(" << point.getX() << ", " << point.getY() << ", " << w << ", " << h << ", ordre: " << ordre << ")";
    return ss.str();
}