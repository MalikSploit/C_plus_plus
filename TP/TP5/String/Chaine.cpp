//
// Created by root on 12/11/23.
//

#include "Chaine.hpp"

Chaine::Chaine() : capa(0), tab(nullptr){}
Chaine::Chaine(int pCapa) : capa(pCapa+1), tab(new char[pCapa]){
    *tab = '\0';
}
Chaine::Chaine(const char *cstr) : capa((int)strlen(cstr) + 1), tab(new char[capa]){
    strcpy(tab, cstr);
}
Chaine::Chaine(const Chaine &uC) : capa(uC.capa), tab(new char[uC.capa]){
    std::cout << "Constructeur de copie appelé" << std::endl;
    strcpy(tab, uC.tab);
}
Chaine::~Chaine(){
    delete [] tab;
}


void Chaine::remplacer(const char *c) {
    strncpy(tab, c, capa-1);
    tab[capa-1] = '\0';
}
void Chaine::afficher(std::ostream& os) const {
    if (tab) {
        os << tab;
    }
}
int Chaine::getCapacite() const{
    return tab ? capa-1 : -1;
}
const char* Chaine::c_str() const{
    return tab;
}


std::ostream & operator<<(std::ostream &os, const Chaine &ch) {
    if (ch.tab){
        os << ch.tab;
    }
    return os;
}
const char & Chaine::operator[](int index) const{
    return tab[index];
}
char &Chaine::operator[](int index) {
    return tab[index];
}
Chaine& Chaine::operator=(const Chaine &uC) {
    if (this != &uC) {
        delete[] tab;
        capa = uC.capa;
        tab = new char[capa];
        strcpy(tab, uC.tab);
    }
    return *this;
}