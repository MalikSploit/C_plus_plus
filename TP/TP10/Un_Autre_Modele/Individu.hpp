//
// Created by root on 1/11/24.
//

#ifndef C___INDIVIDU_HPP
#define C___INDIVIDU_HPP
#include <iostream>

class Individu {
protected:
    std::string nom;
    int intelligence;
    int force;
    int vitesse;
    int vitalite;
    int potentielMagie;

public:
    Individu(std::string nom, int intelligence, int force, int vitesse, int vitalite, int potentielMagie);
    virtual ~Individu() {}
};


#endif //C___INDIVIDU_HPP
