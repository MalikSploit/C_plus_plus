#include "Vecteur.hpp"
#include <algorithm> // Pour std::copy
#include <cstring> // Pour std::memcpy

Vecteur::Vecteur(std::size_t capacite_initiale)
        : elements(new double[capacite_initiale]), capacite(capacite_initiale), nb_elements(0) {}

Vecteur::~Vecteur() {
    delete[] elements;
}

Vecteur::Vecteur(const Vecteur& autre)
        : elements(new double[autre.capacite]), capacite(autre.capacite), nb_elements(autre.nb_elements) {
    std::memcpy(elements, autre.elements, nb_elements * sizeof(double));
}

Vecteur& Vecteur::operator=(const Vecteur& autre) {
    if (this != &autre) {
        double* nouveauxElements = new double[autre.capacite];
        std::memcpy(nouveauxElements, autre.elements, autre.nb_elements * sizeof(double));
        delete[] elements;
        elements = nouveauxElements;
        capacite = autre.capacite;
        nb_elements = autre.nb_elements;
    }
    return *this;
}

std::size_t Vecteur::capacity() const {
    return capacite;
}

std::size_t Vecteur::size() const {
    return nb_elements;
}

void Vecteur::push_back(double valeur) {
    if (nb_elements >= capacite) {
        augmenterCapacite();
    }
    elements[nb_elements++] = valeur;
}

double& Vecteur::operator[](std::size_t index) {
    // À compléter : ajouter éventuellement une vérification d'indice
    return elements[index];
}

const double& Vecteur::operator[](std::size_t index) const {
    // À compléter : ajouter éventuellement une vérification d'indice
    return elements[index];
}

Vecteur Vecteur::operator+(const Vecteur& autre) const {
    // À implémenter : concaténation de deux vecteurs
}

void Vecteur::augmenterCapacite() {
    capacite *= 2;
    double* nouveauxElements = new double[capacite];
    std::memcpy(nouveauxElements, elements, nb_elements * sizeof(double));
    delete[] elements;
    elements = nouveauxElements;
}
