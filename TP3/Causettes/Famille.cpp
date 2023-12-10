//
// Created by root on 12/6/23.
//

#include "../../TP2/Bavarde.hpp"
#include <cstdlib>

class Famille{
private:
    Bavarde *membres;
    int taille;

public:
    Famille(int taille): taille(taille){
        if (taille > 0)
        {
            membres = new Bavarde[taille];
        }
        else
        {
            membres = nullptr;
        }
    }

    ~Famille(){
        delete[] membres;
    }
};

int main()
{
    Famille famille(4);

    /*Bavarde *bavarde1 = (Bavarde*) malloc(sizeof(Bavarde));
    bavarde1->afficher();
    free(bavarde1);

    Bavarde *bavarde2 = new Bavarde;
    bavarde2->afficher();
    delete bavarde2;*/

    return 0;
}