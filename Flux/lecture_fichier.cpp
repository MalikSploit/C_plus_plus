//
// Created by root on 12/6/23.
//


#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string nom = "mon_fichier.txt";
    std::ifstream fichier(nom.c_str());

    if (fichier.is_open()) {
        std::string ligne;
        std::cout << "Contenu du fichier :" << std::endl;

        while (std::getline(fichier, ligne)) {
            std::cout << ligne << std::endl;
        }

        fichier.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }

    return 0;
}
