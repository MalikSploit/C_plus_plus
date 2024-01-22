//
// Created by root on 1/11/24.
//

#include "Humain.hpp"

Humain::Humain(const std::string &n, Genre g, int a) : nom(n), genre(g), age(a) {}

std::string Humain::getNom() const{
    return nom;
}
Genre Humain::getGenre() const {
    return genre;
}
int Humain::getAge() const {
    return age;
}

void Humain::setNom(const std::string &n){
    nom = n;
}

void Humain::setGenre(const Genre g){
    genre = g;
}

void Humain::setAge(const int a) {
    age = a;
}