//
// Created by root on 11/30/23.
//
#include "Rectangle.cpp"
#include "Cercle.cpp"
#include "Liste.hpp"

int main()
{
    Rectangle rectangle(4,4, 5, 10);
    std::cout << rectangle.toString() << std::endl;

    Cercle cercle(4,4, 5, 10);
    std::cout << cercle.toString() << std::endl;

    Liste maListe;
    maListe.addCercle(new Cercle(10, 10,5,5));
    maListe.addRectangle(new Rectangle(20, 20, 10, 5));
    std::cout << maListe.toString() << std:endl;
    std::cout << "Formes created: " << Forme::getNbFormes() << std::endl;

    return 0;
}