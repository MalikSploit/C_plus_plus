//
// Created by root on 12/7/23.
//

#include "Rectangle.hpp"
#include "Cercle.hpp"
#include <string>
#include <sstream>

#ifndef C_LISTE_HPP
#define C_LISTE_HPP

const int MAX_SIZE = 100;

class Liste{
public:
    int nb_c;
    int nb_r;
    int compteur;
    Cercle *cercles[MAX_SIZE];
    Rectangle *rectangles[MAX_SIZE];

    Liste();
    ~Liste();
    std::string toString() const;

    void addCercle(Cercle *cercles);
    void addRectangle(Rectangle *rectangle);
    int getCompteur() const;
};

#endif //C_LISTE_HPP
