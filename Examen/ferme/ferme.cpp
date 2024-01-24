#include "ferme.hpp"

Produit::Produit(const std::string n) : nom(n){}

std::string Produit::getNom() const {
    return nom;
}

bool Produit::isEqual(const Produit p) const {
    return this->nom == p.nom;
}

bool Produit::operator==(const Produit& p) const{
    return this->nom == p.nom;
}

std::ostream & operator<<(std::ostream &os, const Produit &p) {
    os << p.nom;
    return os;
}

PeutPasProduireException::PeutPasProduireException() {}

const char *PeutPasProduireException::what() const noexcept {
    return "peut_pas_produire";
}


Animal::Animal() : malade(0) {
    ++compteur;
}

Animal::Animal(const Animal & other) : malade(other.malade){
    ++compteur;
}

Animal::~Animal(){}

void Animal::setMalade(bool mal) {
    malade = mal;
}

int Animal::getCompteur() {
    return compteur;
}


Vache::Vache(const std::string sn) : Animal(), surnom(sn){}

std::string Vache::getNom() const{
    return surnom;
}

Produit Vache::produire() const{
    if (!malade){
        return Produit("lait");
    }
    throw PeutPasProduireException();
}

void Vache::meugler(std::ostream &os) const{
    os << "la vache " << surnom << " meugle";
}

void Vache::communiquer(std::ostream & os) {
    meugler(os);
}

std::string Poule::typeAnimal() const {
    return "Vache";
}


Poule::Poule(std::string sn) : Animal(), surnom(sn){}

std::string Poule::getNom() const{
    return surnom;
}

Produit Poule::produire() const{
    if (!malade){
        return Produit("oeuf");
    }
    throw PeutPasProduireException();
}

void Poule::glousser(std::ostream &os) const{
    os << "la poule " << surnom << " glousse";
}

void Poule::communiquer(std::ostream & os) {
    glousser(os);
}

std::string Vache::typeAnimal() const {
    return "Poule";
}


Communiquer::Communiquer() {}

Communiquer::~Communiquer(){}


Ferme::Ferme() {}

Ferme::~Ferme() {
    for (Animal* animal : animaux){
        delete animal;
    }
}

bool Comparer(Animal * a, Animal *b){
    if (a->typeAnimal() == b->typeAnimal()){
        return a->getNom() < b->getNom();
    }
    return a->typeAnimal() > b->typeAnimal();
}

void Ferme::acheter(Animal *animal) {
    animaux.push_back(animal);
    std::sort(animaux.begin(), animaux.end(), Comparer);
}

int Ferme::size() {
    return animaux.size();
}

void Ferme::nourrirAnimaux(std::ostream &os) {
    for (Animal * animal : animaux){
        animal->communiquer(os);
        os << "\n";
    }
}

Animal * Ferme::vendre(const std::string & nom){
    for (auto it = animaux.begin(); it!= animaux.end(); ++it){
        if ((*it)->getNom() == nom){
            Animal * animalAVendre = *it;
            animaux.erase(it);
            return animalAVendre;
        }
    }
    return nullptr;
}