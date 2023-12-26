//
// Created by root on 12/20/23.
//
#include <vector>
#include "Groupe.cpp"
#include "Cercle.cpp"

int main() {
    // Création d'instances de formes
    auto *c1 = new Cercle();

    // Création d'un groupe et ajout de formes
    auto *g1 = new Groupe();
    g1->ajouter(c1);

    // Clonage du groupe
    auto *g2 = static_cast<Groupe*>(g1->clone());

    delete g1;
    delete g2;

    return 0;
}

