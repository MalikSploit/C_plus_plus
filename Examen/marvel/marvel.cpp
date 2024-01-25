#include "marvel.hpp"

Personne::Personne(const std::string p, const std::string n, const Personne::Genre g) : prenom(p), nom(n), genre(g){}

Personne::Personne(const Personne & personne) : prenom(personne.prenom), nom(personne.nom), genre(personne.genre) {}

std::string Personne::getNom() const{
    return nom;
}

std::string Personne::getPrenom() const{
    return prenom;
}

Personne::Genre Personne::getGenre() const{
    return genre;
}

void Personne::setPrenom(const std::string p) {
    prenom = p;
}

void Personne::setNom(const std::string n){
    nom = n;
}

void Personne::setGenre(const Personne::Genre g) {
    genre = g;
}

void Personne::afficher(std::ostream &os) {
    switch (getGenre()) {
        case HOMME:
            os << getPrenom() << " " << getNom() << " " << "[HOMME]";
            break;
        case FEMME:
            os << getPrenom() << " " << getNom() << " " << "[FEMME]";
            break;
        default:
            os << getPrenom() << " " << getNom() << " " << "[INDETERMINE]";
            break;
    }
}

bool Personne::operator==(const Personne &personne) const{
    return getNom() == personne.getNom() && getPrenom() == personne.getPrenom() && getGenre() == personne.getGenre();
}

std::ostream & operator<<(std::ostream & os, const Personne personne){
    switch (personne.getGenre()) {
        case Personne::Genre::HOMME:
            os << personne.getPrenom() << " " << personne.getNom() << " " << "[HOMME]";
            break;
        case Personne::Genre::FEMME:
            os << personne.getPrenom() << " " << personne.getNom() << " " << "[FEMME]";
            break;
        default:
            os << personne.getPrenom() << " " << personne.getNom() << " " << "[INDETERMINE]";
            break;
    }
    return os;
}

Personne & Personne::operator=(const Personne &personne) {
    if (this != &personne){
        prenom = personne.prenom;
        nom = personne.nom;
        genre = personne.genre;
    }
    return *this;
}

Personne Personne::INCONNU = Personne();


Super::Super(std::string p, Personne i) : pseudo(p), anonyme(true), identite(i) {}

Super::Super(const Super& other)
        : Personne(other), pseudo(other.pseudo), anonyme(other.anonyme), identite(other.identite) {
    for (auto cap : other.capacites) {
        capacites.push_back(cap->clone());
    }
}
Super::~Super(){
    for (auto it : capacites){
        delete it;
    }
}

bool Super::estAnonyme() {
    return anonyme;
}

std::string Super::getNom() const {
    return pseudo;
}

void Super::enregistrer() {
    anonyme = false;
}

Personne Super::getIdentite() {
    if (!anonyme){
        return identite;
    }
    throw AnonymeException();
}

void Super::setIdentite(const Personne & p) {
    identite = p;
    anonyme = true;
}

int Super::getNiveau() const{
    int niveau = 0;
    for (auto it : capacites){
        niveau += it->getNiveau();
    }
    return niveau;
}

void Super::ajouter(Capacite * capacite){
    capacites.push_back(capacite);
}

void Super::setNom(const std::string &newPseudo) {
    pseudo = newPseudo;
}

Super& Super::operator=(const Super& other) {
    if (this != &other) {
        Personne::operator=(other);
        pseudo = other.pseudo;
        anonyme = other.anonyme;
        identite = other.identite;

        for (auto cap : capacites) {
            delete cap;
        }
        capacites.clear();

        for (auto cap : other.capacites) {
            capacites.push_back(cap->clone());
        }
    }
    return *this;
}


AnonymeException::AnonymeException() {}

const char *AnonymeException::what() const noexcept {
    return "identite anonyme";
}


Capacite::Capacite(std::string c, int n) : capacite(c), niveau(n){}

Capacite::~Capacite(){}

int Capacite::getNiveau() const {
    return niveau;
}

std::string Capacite::getCapacite() const {
    return capacite;
}

std::string Capacite::getNom() const {
    return getCapacite();
}

Materiel::Materiel(std::string c, int n) : Capacite(c, n){}

void Materiel::actionner(std::ostream &os) const {
    os << getCapacite() << " [" << getNiveau() << "] " << "en action";
}

void Materiel::utiliser(std::ostream &os) const{
    actionner(os);
}


Physique::Physique(std::string c, int n) : Capacite(c, n){}

void Physique::exercer(std::ostream &os) const {
    os << getCapacite() << " [" << getNiveau() << "]";
}

void Physique::utiliser(std::ostream &os) const{
    exercer(os);
}


Psychique::Psychique(std::string c, int n) : Capacite(c, n){}

void Psychique::penser(std::ostream &os) const {
    os << getCapacite() << " [" << getNiveau() << "]";
}

void Psychique::utiliser(std::ostream &os) const{
    penser(os);
}


Equipe::Equipe(std::string n) : nom(n), nombre(0){}

Equipe::~Equipe(){
    for (auto it : supers){
        delete it;
    }
}

int Equipe::getNombre() const {
    return nombre;
}

void Equipe::ajouter(Super *super) {
    supers.push_back(super);
    ++nombre;
}

int Equipe::getNiveau() const {
    int niveau = 0;
    for (auto it : supers){
        niveau += it->getNiveau();
    }
    return niveau;
}

