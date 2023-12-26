//
// Created by root on 12/7/23.
//
#include "random"
#include "Producteur.hpp"
#include "Producteur.hpp"

#ifndef C_PRODUCTEURALEATOIRE_H
#define C_PRODUCTEURALEATOIRE_H

class ProducteurAleatoire: public Producteur{
public:
    void produire(int nombre, const std::string& nomFichier) override;
};

#endif //C_PRODUCTEURALEATOIRE_H
