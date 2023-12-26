//
// Created by root on 11/30/23.
//

#include "Bavarde.hpp"

Bavarde::Bavarde(int p) : Inconnu(p)
{
    count++;
}

Bavarde::Bavarde(const Bavarde& copie) : Inconnu(copie.Inconnu){
    count++;

}

Bavarde::~Bavarde()
{
    count--;
    std::cout << "Tais-toi " << Inconnu << std::endl;
}

int Bavarde::get() const {
    return Inconnu;
}

// Variables globales ou fonctions liées à Bavarde
//Bavarde bizarre(1);
//Bavarde globale(2);

void fonction(Bavarde b) {
    std::cout << "code de la fonction" << std::endl;
}

void Bavarde::afficher() const
{
    std::cout << "Affichage de " << Inconnu << std::endl;
}

int Bavarde::getCount() {
    return count;
}

/*
int main(int, char **) {
    Bavarde b1(3);
    Bavarde b2(4);
    Bavarde * p = new Bavarde(5);
    std::cout << Bavarde(100).get() << std::endl;
    // fonction(b1);

    delete p;

    return 0;
}*/
