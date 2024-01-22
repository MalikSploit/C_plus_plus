//
// Created by root on 12/7/23.
//

#include "Liste.hpp"

Liste::Liste(): nb_c(0), nb_r(0), compteur(0) {
    for (int i = 0; i < MAX_SIZE; ++i){
        cercles[i] = nullptr;
        rectangles[i] = nullptr;
    }
}

Liste::~Liste() {
    for (int i = 0; i < nb_c; ++i) {
        delete cercles[i];
        cercles[i] = nullptr;
    }
    for (int i = 0; i < nb_r; ++i) {
        delete rectangles[i];
        rectangles[i] = nullptr;
    }
}

int Liste::getCompteur() const{
    return compteur;
}

std::string Liste::toString() const {
    std::stringstream ss;
    for (int i = 0; i < nb_c; i++) {
        if (cercles[i] != nullptr) {
            ss << cercles[i]->toString() << std::endl;
        }
    }
    for (int i = 0; i < nb_r; i++) {
        if (rectangles[i] != nullptr) {
            ss << rectangles[i]->toString() << std::endl;
        }
    }
    return ss.str();
}

void Liste::addCercle(Cercle *cercle){
    if (nb_c < MAX_SIZE){
        cercles[nb_c] = cercle;
        cercles[nb_c]->setOrdre(compteur++);
        nb_c++;
    }
}

void Liste::addRectangle(Rectangle *rectangle){
    if (nb_r < MAX_SIZE){
        rectangles[nb_r] = rectangle;
        rectangles[nb_r]->setOrdre(compteur++);
        nb_r++;
    }
}