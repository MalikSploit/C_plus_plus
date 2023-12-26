#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <cstddef> // Pour std::size_t

class Vecteur {
public:
    Vecteur(std::size_t capacite_initiale = 10);
    ~Vecteur();
    Vecteur(const Vecteur& autre); // Constructeur de copie
    Vecteur& operator=(const Vecteur& autre); // Opérateur d'affectation

    std::size_t capacity() const;
    std::size_t size() const;
    void push_back(double valeur);

    double& operator[](std::size_t index); // Accès en lecture/écriture
    const double& operator[](std::size_t index) const; // Accès en lecture seule

    Vecteur operator+(const Vecteur& autre) const; // Concaténation

private:
    double* elements;
    std::size_t capacite;
    std::size_t nb_elements;

    void augmenterCapacite();
};

#endif // VECTEUR_HPP
