#include "deviant.hpp"

Personne::Personne(const std::string n) : Individu(), nom(n){
    Cite::getCite().addResident(this);
}

Personne::Personne() : Individu(), nom("inconnu"){
    Cite::getCite().addResident(this);
}

Personne::~Personne(){
    Cite::getCite().removeResident(this->getId());
}

std::string Personne::getNom() const
{
    return nom;
}

void Personne::setNom(const std::string n)
{
    nom = n;
}

void Personne::afficher(std::ostream &os) const {
    os << nom << " ";
    Individu::afficher(os);
}

TYPE Personne::getType() const {
    return TYPE::PERSONNE;
}


Individu::Individu() : id(++compteur){}

Individu::~Individu() {}

int Individu::getCompteur()
{
    return compteur;
}

int Individu::getId() const
{
    return id;
}

void Individu::afficher(std::ostream & os) const
{
    os << id;
}

std::ostream & operator<<(std::ostream & os, const Individu& individu){
    individu.afficher(os);
    return os;
}

TYPE Individu::getType() const
{
    throw IllegalException();
}


IllegalException::IllegalException(){}

const char *IllegalException::what() const noexcept
{
    return "illegal exception";
}


void Cite::addResident(Individu *resident) {
    residents.push_back(resident);
}

MatchId::MatchId(int id) : id(id) {}

bool MatchId::operator()(const Individu *resident) const {
    return resident->getId() == id;
}

void Cite::removeResident(int id) {
    auto it = std::remove_if(residents.begin(), residents.end(), MatchId(id));
    if (it != residents.end()) {
        residents.erase(it, residents.end());
    }
}

int Cite::size() const {
    return residents.size();
}

Cite & Cite::getCite() {
    static Cite instance;
    return instance;
}


Deviant::Deviant(const Personne &personne) : Individu(personne){
    Cite::getCite().removeResident(this->getId());
}

Deviant::Deviant(const Personne &personne, const std::string d) : Individu(personne), date(d){
    Cite::getCite().removeResident(this->getId());
}

void Deviant::setObs(const std::string d) {
    date = d;
}

std::string Deviant::getObs() const{
    return date;
}

int Deviant::getId() const {
    return Individu::getId();
}

bool Deviant::operator<(const Deviant &other) const {
    return this->date < other.date;
}

TYPE Deviant::getType() const {
    return TYPE::DEVIANT;
}


void Covid::push(Deviant &d) {
    deviants.push_back(&d);
    std::sort(deviants.begin(), deviants.end(), compareByDate);
}

void Covid::pop() {
    if (!deviants.empty()){
        deviants.pop_back();
    }
}

Deviant &Covid::top() const{
    if (!deviants.empty()){
        return *deviants.back();
    }
    throw std::out_of_range("Covid is empty");
}

bool Covid::compareByDate(const Deviant *a, const Deviant *b) {
    return a->getObs() < b->getObs();
}