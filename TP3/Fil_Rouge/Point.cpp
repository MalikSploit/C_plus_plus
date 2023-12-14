//
// Created by root on 12/7/23.
//

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int nb) {
    this->x = nb;
}

void Point::setY(int nb) {
    this->y = nb;
}

const Point Point::ORIGINE = Point();