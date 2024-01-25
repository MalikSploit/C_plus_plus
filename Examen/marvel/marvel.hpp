#ifndef marvel__hpp
#define marvel__hpp

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <sstream>
#include "vector"

class Personne{
public:
    enum Genre {HOMME, FEMME, INDETERMINE};
    static Personne INCONNU;
private:
    std::string prenom;
    std::string nom;
    Genre genre;
public:
    Personne(const std::string p="Inconnu", const std::string n="Inconnu", const Genre g=Genre::INDETERMINE);
    Personne(const Personne & personne);
    std::string getPrenom() const;
    virtual std::string getNom() const;
    void setPrenom(const std::string p);
    void setNom(const std::string n);
    void setGenre(const Genre);
    Genre getGenre() const;
    void afficher(std::ostream  & os);
    bool operator==(const Personne & personne) const;
    friend std::ostream & operator<<(std::ostream & os, const Personne personne);
    Personne & operator=(const Personne & personne);
};

class Capacite{
private:
    std::string capacite;
    int niveau;
public:
    Capacite(std::string c, int n);
    virtual ~Capacite();
    virtual void utiliser(std::ostream  & os) const = 0;
    int getNiveau() const;
    std::string getCapacite() const;
    std::string getNom() const;
    virtual Capacite* clone() const = 0;
};

class Super : public Personne{
private:
    std::string pseudo;
    bool anonyme;
    Personne identite;
    std::vector<Capacite *> capacites;
public:
    Super(std::string pseudo, Personne i);
    Super(const Super & super);
    virtual ~Super();
    bool estAnonyme();
    std::string getNom() const override;
    void enregistrer();
    Personne getIdentite();
    void setIdentite(const Personne & p);
    void setNom(const std::string & newPseudo);
    int getNiveau() const;
    void ajouter(Capacite * capacite);
    Super & operator=(const Super& other);
};

class AnonymeException : public std::exception{
public:
    AnonymeException();
    const char *what() const noexcept override;
};

class Materiel : public Capacite{
public:
    Materiel(std::string c, int n);
    Materiel* clone() const override {
        return new Materiel(*this);
    }
    void actionner(std::ostream & os) const;
    void utiliser(std::ostream  & os) const override;
};

class Physique : public Capacite{
public:
    Physique(std::string c, int n);
    Physique* clone() const override {
        return new Physique(*this);
    }
    void exercer(std::ostream & os) const;
    void utiliser(std::ostream & os) const override;
};

class Psychique : public Capacite{
public:
    Psychique(std::string c, int n);
    Psychique* clone() const override {
        return new Psychique(*this);
    }
    void penser(std::ostream & os) const;
    void utiliser(std::ostream & os) const override;
};


class Equipe{
private:
    std::string nom;
    std::vector<Super *> supers;
    int nombre;

public:
    Equipe(std::string n);
    ~Equipe();
    int getNombre() const;
    int getNiveau() const;
    void ajouter(Super * super);
};

#endif
