//
// Created by root on 12/7/23.
//

#include "Rectangle.hpp"
#include "Cercle.hpp"
#include <string>

#ifndef C___LISTE_HPP
#define C___LISTE_HPP

const int MAX_SIZE = 100;

class Liste{
public:
    int nb_c;
    int nb_r;
    int compteur;
    Cercle *cercle[MAX_SIZE];
    Rectangle *rectangles[MAX_SIZE];

    Liste();
    ~Liste();
    std::string toString() const;

    void addCercle(Cercle *cercle);
    void addRectangle(Rectangle *rectangle);
};

#endif //C___LISTE_HPP
