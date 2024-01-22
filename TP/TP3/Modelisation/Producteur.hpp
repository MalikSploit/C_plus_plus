//
// Created by root on 12/6/23.
//

#include "iostream"
#include <fstream>

#ifndef C_PRODUCTEUR_H
#define C_PRODUCTEUR_H

class Producteur{
public:
    Producteur();
    virtual ~Producteur();
    virtual void produire(int nombre, const std::string& nomFichier) = 0;
    int getTravail() const;

protected:
    int travail = 0;
};

#endif //C_PRODUCTEUR_H
