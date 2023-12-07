//
// Created by root on 12/7/23.
//

#include "ProducteurAleatoire.hpp"

void ProducteurAleatoire::produire(int nombre, const std::string &nomFichier) {
    std::ofstream  fichier(nomFichier);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    if (fichier.is_open()){
        fichier << nombre << std::endl;
        for (int i = 0; i < nombre; ++i){
            fichier << dis(gen) << std::endl;
        }
    }
    travail++;
}