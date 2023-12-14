//
// Created by root on 12/7/23.
//
#include "Forme.hpp"

Forme::Forme() : point(Point::ORIGINE), couleur(COULEURS::BLEU), id(nbFormes++) {}

Forme::Forme(const Point& p, COULEURS c) : point(p), couleur(c), id(nbFormes++) {}

Point Forme::getPoint() const {
    return point;
}

void Forme::setX(int x) {
    point.setX(x);
}

void Forme::setY(int y) {
    point.setY(y);
}

COULEURS Forme::getCouleur() const {
    return couleur;
}

void Forme::setCouleur(COULEURS c) {
    couleur = c;
}

int Forme::getId() const {
    return id;
}

int Forme::prochainId() {
    return nbFormes;
}