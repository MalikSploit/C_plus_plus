#include "gangster.hpp"

Personne::Personne(const std::string n) : nom(n) {}

Personne::~Personne(){}

std::string Personne::getNom() const{
    return nom;
}

void Personne::setNom(const std::string n) {
    nom = n;
}

bool Personne::equals(const Personne personne) const{
    return getNom() == personne.getNom();
}


Gangster::Gangster(int i) : Personne("inconnu"), influence(i) ,identifiant(++compteur){}

Gangster::~Gangster(){}

int Gangster::getId() const{
    return identifiant;
}

int Gangster::getInfluence() const{
    return influence;
}

void Gangster::setInfluence(int i) {
    influence = i;
}

Personne Gangster::getPersonne() const {
    if (getNom() == "inconnu") {
        throw InconnuException();
    }
    return *this;
}

void Gangster::setPersonne(Personne personne) {
    setNom(personne.getNom());
}

bool Gangster::operator<(const Gangster& gangster) const {
    if (influence == gangster.getInfluence()) {
        return identifiant > gangster.getId();
    }
    return influence < gangster.getInfluence();
}


Chef::Chef() : Gangster(1){}

void Chef::commande(Gangster *gangster) {
    if (!bonusAjoute){
        setInfluence(getInfluence() + bonus);
        bonusAjoute = true;
    }
    setInfluence(getInfluence()+gangster->getInfluence());
}


InconnuException::InconnuException() {}

const char *InconnuException::what() const noexcept {
    return "personnalite inconnue";
}


Famille::~Famille(){
    for (auto it : gangsters){
        delete it;
    }
    gangsters.clear();
}

void Famille::ajouter(Gangster* gangster) {
    gangsters.push_back(gangster);
}

void Famille::listePersonnes(std::ostream &os) {
    std::sort(gangsters.begin(), gangsters.end(), [](Gangster *gangster1, Gangster *gangster2){return gangster1->getNom() < gangster2->getNom();});
    bool isFirst = true;
    for (auto it : gangsters) {
        if (it->getNom() != "inconnu"){
            if (!isFirst) {
                os << ", ";
            } else {
                isFirst = false;
            }
            os << it->getNom();
        }
    }
}

std::ostream & operator<<(std::ostream & os, const Famille & famille){
    auto sortedGangsters = famille.gangsters;
    std::sort(sortedGangsters.begin(), sortedGangsters.end(), [](Gangster *gangster1, Gangster *gangster2){return gangster1->getNom() < gangster2->getNom();});
    bool isFirst = true;
    for (auto it : sortedGangsters) {
        if (it->getNom() != "inconnu"){
            if (!isFirst) {
                os << ", ";
            } else {
                isFirst = false;
            }
            os << it->getNom();
        }
    }
    return os;
}

void Famille::listeMembres(std::ostream &os) {
    std::sort(gangsters.begin(), gangsters.end(), [](Gangster *gangster1, Gangster *gangster2){return gangster1->getInfluence() > gangster2->getInfluence();});

    for (auto it = gangsters.begin(); it!= gangsters.end(); ++it){
        os << (*it)->getId();
        if (it != gangsters.end() - 1){
             os << " ";
        }
    }
}


FoncteurInf::FoncteurInf() {}

bool FoncteurInf::operator()(Gangster *gangster1, Gangster *gangster2) {
    if (gangster1->getInfluence() == gangster2->getInfluence()) {
        return gangster1->getId() > gangster2->getId();
    }
    return gangster1->getInfluence() < gangster2->getInfluence();
}