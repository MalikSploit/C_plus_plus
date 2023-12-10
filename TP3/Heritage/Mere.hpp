//
// Created by root on 12/6/23.
//
#include <string>
#include <iostream>

#ifndef C_MERE_H
#define C_MERE_H

class Mere{
private:
    static int nombre;
    std::string nom;
public:
    explicit Mere(std::string valeur);
    virtual ~Mere();
    static int getCompteur() ;
    std::string getName();
    virtual void afficher();
};

#endif //C_MERE_H
