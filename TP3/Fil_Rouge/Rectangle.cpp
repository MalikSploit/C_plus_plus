//
// Created by root on 11/30/23.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h), ordre(0){}
std::string Rectangle::toString() const {
    return "RECTANGLE " + std::to_string(x)  + " " + std::to_string(y) + " " + std::to_string(w) + " " + std::to_string(h);
}