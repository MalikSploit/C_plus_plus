//
// Created by root on 12/6/23.
//

#include "Producteur.hpp"

int Producteur::getTravail() const{
    return travail;
}

/*void Producteur::produire(int nombre, const std::string& nomFichier){
    std::ofstream fichier(nomFichier);
    if (fichier.is_open()){
        fichier << nombre << std::endl;
        for (int i = 1; i <= nombre; ++i){
            fichier << i << std::endl;
        }
    }
    travail++;
}*/

Producteur::Producteur(){
    std::cout << "Construction Done" << std::endl;
}