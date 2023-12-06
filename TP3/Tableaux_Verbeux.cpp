//
// Created by root on 12/6/23.
//

#include "../TP2/Bavarde.hpp"

int main(int, char **) {
    const int TAILLE = 20;
    Bavarde   tab1[TAILLE];
    Bavarde * tab2 = new Bavarde[TAILLE];
    // Combien d'instances sont créées ? 40

    for (int i =0; i < TAILLE; ++i) {
        tab1[i].afficher();
        tab2[i].afficher();
    }
    delete[] tab2;

    // Combien d'instances sont détruites ? 40, 20 automatiquement et 20 manuellement
    return 0;
}