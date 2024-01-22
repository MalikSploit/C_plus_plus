//
// Created by root on 12/7/23.
//

#include <iostream>
#include <fstream>
#include <string>

#ifndef C_STATISTICIEN_H
#define C_STATISTICIEN_H

class Statisticien{
public:
    Statisticien();
    void acquerir(const std::string& nomFichier);
    bool estCalculDisponible() const;
    double getSomme() const;
    double getMoyenne() const;
private:
    bool calcul;
    double somme;
    double moyenne;
};

#endif //C_STATISTICIEN_H
