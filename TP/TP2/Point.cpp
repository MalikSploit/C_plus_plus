//
// Created by root on 11/30/23.
//

#include <iostream>
#include "Point.hpp"

int Point::compteur = 0;

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int number)
{
    this->x = number;
}

void Point::deplacerDe(int num1, int num2)
{
    this->x += num1;
    this->y += num2;
}

void Point::deplacerVers(int num1, int num2)
{
    this->x = num1;
    this->y = num2;
}


Point::Point() : x(0), y(0) {
    std::cout << "Constructeur sans argument appelé" << std::endl;
    compteur++;
}

Point::Point(int x, int y) : x(x), y(y) {
    std::cout << "Constructeur avec arguments appelé" << std::endl;
    compteur++;
}

int Point::getCompteur()
{
    return compteur;
}
