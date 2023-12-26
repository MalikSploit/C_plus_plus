#include "Pile.hpp"

Pile::Pile(int cap) : topPile(0) {
    if (cap <= 0){
        throw ExceptionPile("Erreur: Capacité ne peut pas etre négative");
    }
    capacite = cap;
    tab = new int[capacite];
}

Pile::Pile() : capacite(0), topPile(0) {}

Pile::~Pile(){
    delete [] tab;
}

bool Pile::empty() const {
    return topPile == 0;
}

int Pile::size() const {
    return topPile;
}

int Pile::top() const {
    if (tab == nullptr){
        throw ExceptionPile("Erreur: Tableau non initialisé");
    }
    if (empty()){
        throw ExceptionPile("Erreur: Pile vide");
    }
    return tab[topPile-1];
}

void Pile::pop() {
    if (empty()){
        throw ExceptionPile("Erreur: Pile vide");
    }
    --topPile;
}

void Pile::push(int val) {
    if (tab == nullptr){
        throw ExceptionPile("Erreur: tableau non initialisé");
    }
    if (topPile >= capacite){
        throw ExceptionPile("Erreur: Pile Pleine");
    }
    tab[topPile++] = val;
}

Pile::ExceptionPile::ExceptionPile(std::string errMsg) noexcept : errorMessage(std::move(errMsg)){}

const char *Pile::ExceptionPile::what() const noexcept{
    return exception::what();
}

