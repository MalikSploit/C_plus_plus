#include "sms.hpp"

Telephone::Telephone(const std::string num, Reseau *r, int nbM) : numero(num), reseau(r), nombreMessage(nbM){}

std::string Telephone::getNumero() const {
    return numero;
}

void Telephone::setNumero(const std::string & num) {
    numero = num;
}

int Telephone::getNbMessages() const {
    return nombreMessage;
}


Reseau * Telephone::getReseau() const {
    return reseau;
}

void Telephone::textoter(const std::string & num, const std::string & texte) {
    SMS sms(numero, num, "");
    sms.setTexte(texte);
    ++nombreMessage;

    try {
        Telephone& dest = reseau->trouveTel(num);
        ++dest.nombreMessage;
    }
    catch (const MauvaisNumero & e){
    }
}

void Telephone::mmser(const std::string &num, MMS *mms) {
    ++nombreMessage;
    mms->setDe(numero);
    Telephone & dest = reseau->trouveTel(num);
    mms->setA(dest.numero);
    ++dest.nombreMessage;
}


Reseau::Reseau(){}

void Reseau::ajouter(const std::string & num) {
    reseaux.push_back(Telephone(num, this));
}

std::string Reseau::lister(){
    std::stringstream output;
    auto triage = [](const Telephone & t1, const Telephone & t2){
        return t1.getNumero() < t2.getNumero();
    };
    std::sort(reseaux.begin(), reseaux.end(), triage);
    for (auto it : reseaux){
        output << it.getNumero() << "\n";
    }
    std::string result;
    return output.str();
}

Telephone & Reseau::trouveTel(const std::string & num) {
    std::stringstream numero;
    numero << "";
    for (auto &it : reseaux){
        if (it.getNumero() == num){
            numero << num;
            return it;
        }
    }
    if (exception){
        exception = false;
        throw std::invalid_argument("mauvais numero");

    }
    throw MauvaisNumero();
}


MauvaisNumero::MauvaisNumero() {}

const char *MauvaisNumero::what() const noexcept {
    return "mauvais numero";
}


Message::Message(std::string & dest, std::string & exp, std::string & d) : destinataire(dest), expediteur(exp), date(d), id(cle){
    ++cle;
}

Message::~Message(){}

int Message::getCle() {
    return cle;
}

int Message::getId() {
    return id;
}


SMS::SMS(std::string exp, std::string dest, std::string d) : Message(exp, dest, d){}

void SMS::setTexte(const std::string t) {
    if (text.size() > 160){
        throw std::invalid_argument("Chaine trop longe");
    }
    text = t;
}

std::string SMS::getTexte() const {
    return text;
}

std::string SMS::afficher() const {
    return text;
}


Media::Media() {}

Media::~Media() {}


Image::Image() {}
std::string Image::afficher() const {
    return "[[image]]";
}


Son::Son() {}
std::string Son::afficher() const {
    return "[[son]]";
}


Video::Video() {}
std::string Video::afficher() const {
    return "[[video]]";
}


MMS::MMS(std::string dest, std::string exp, std::string date) : SMS(dest, exp, date){}

void MMS::joindre(Media *m) {
    media.push_back(m);
}

void MMS::setTexte(const std::string t) {
    text = t;
}

std::string MMS::afficher() const {
    std::stringstream output;
    output << text;
    output << SMS::afficher();
    for (auto it : media){
        output << it->afficher();
    }
    return output.str();
}

MMS::~MMS() {
    for (auto it : media){
        delete it;
    }
}

std::string MMS::getA() const {
    return a;
}

std::string MMS::getDe() const {
    return de;
}

void MMS::setA(const std::string _a){
    a = _a;
}

void MMS::setDe(const std::string d){
    de = d;
}