//
// Created by malik on 11/29/2023.
//

#include <iostream>

using std::cout;
using std::endl;

/* on peut utiliser le mot clé const pour définir la taille d'un tableau statique en C++ */
/* Jamais de #define pour cela */

const int TAILLE = 10;

int main(int, char **){
    int tab[TAILLE];

    for (int i=0; i < TAILLE; ++i){
        tab[i] = i % 2;
        cout << tab[i] << " ";
    }

    cout << endl;
    return TAILLE;
}