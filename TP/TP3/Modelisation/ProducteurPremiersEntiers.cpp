//
// Created by root on 12/7/23.
//

#include "ProducteurPremiersEntiers.hpp"

void ProducteurPremiersEntiers::produire(int nombre, const std::string& nomFichier){
    std::ofstream fichier(nomFichier);
    if (fichier.is_open()){
        fichier << nombre << std::endl;
        for (int i = 1; i <= nombre; ++i){
            fichier << i << std::endl;
        }
    }
    travail++;
}
