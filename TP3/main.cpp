//
// Created by root on 12/6/23.
//

#include "Mere.hpp"
#include "Fille.cpp"


int main()
{
    Mere  *pm = new Mere("mere_dyn");
    Fille *pf = new Fille("fille_dyn");
    Mere  *pp = new Fille("fille vue comme mere");
    pm->afficher(); // affiche Mere
    pf->afficher(); // affiche Fille
    pp->afficher(); // affiche Fille

    delete pm;
    delete pf;
    delete pp;
}