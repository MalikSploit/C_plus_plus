// NOM    :
// PRENOM :

#ifndef __gangster_hpp__
#define __gangster_hpp__

#include "iostream"
#include "string"
#include "exception"
#include "vector"
#include "algorithm"
#include <sstream>

class Personne{
private:
    std::string nom;
public:
    Personne(const std::string n);
    ~Personne();
    void setNom(const std::string n);
    std::string getNom() const;
    bool equals(const Personne personne) const;
};

class Gangster : public Personne{
private:
    int influence;
    int identifiant;
    inline static int compteur = 0;
public:
    Gangster(int i= 1);
    virtual ~Gangster();
    int getId() const;
    int getInfluence() const;
    void setInfluence(int i);
    Personne getPersonne() const;
    void setPersonne(Personne personne);
    bool operator<(const Gangster& gangster) const;
};

class Chef : public Gangster{
private:
    inline static int bonus = 9;
    bool bonusAjoute = false;
public:
    Chef();
    void commande(Gangster *gangster);
};


class InconnuException : public std::exception{
public:
    InconnuException();
    virtual const char *what() const noexcept;
};

class Famille{
private:
    std::vector<Gangster*> gangsters;
public:
    ~Famille();
    void ajouter(Gangster* gangster);
    void listePersonnes(std::ostream & os);
    friend std::ostream & operator<<(std::ostream & os, const Famille & famille);
    void listeMembres(std::ostream & os);

};

class FoncteurInf{
public:
    FoncteurInf();
    bool operator()(Gangster  *gangster1, Gangster *gangster2);
};

#endif
