//
// Created by root on 11/30/23.
//
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Liste.hpp"
#include "Forme.hpp"

int main()
{
    Liste maListe;
    maListe.addCercle(new Cercle(10, 10, 5));
    maListe.addRectangle(new Rectangle(20, 20, 10, 5));
    std::cout << maListe.toString() << std::endl;
    std::cout << "Mes Formes : " << Forme::prochainId() << std::endl;
    return 0;
}