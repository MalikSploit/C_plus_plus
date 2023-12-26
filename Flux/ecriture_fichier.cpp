//
// Created by root on 12/6/23.
//

#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string nom = "mon_fichier.txt";
    std::ofstream fichier(nom.c_str());

    if (fichier.is_open()) {
        std::string ligne;
        std::cout << "Entrez votre texte (laissez la ligne vide et appuyez sur Entrée pour terminer) : " << std::endl;

        while (true) {
            std::getline(std::cin, ligne);
            if (ligne.empty()) {
                break;
            }
            fichier << ligne << std::endl;
        }

        fichier.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
    }

    return 0;
}
