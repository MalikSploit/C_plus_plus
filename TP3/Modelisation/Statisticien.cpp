//
// Created by root on 12/7/23.
//

#include "Statisticien.hpp"

Statisticien::Statisticien() : calcul(false), somme(0), moyenne(0){}

void Statisticien::acquerir(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    int nombre;
    int total = 0;
    somme = 0;

    if (fichier.is_open()){
        fichier >> nombre;
        int valeur;
        while (fichier >> valeur){
            somme += valeur;
            total++;
        }
        if (total > 0){
            moyenne = somme / total;
            calcul = true;
        }
    }
}

bool Statisticien::estCalculDisponible() const {
    return calcul;
}

double Statisticien::getSomme() const {
    return somme;
}

double Statisticien::getMoyenne() const {
    return moyenne;
}