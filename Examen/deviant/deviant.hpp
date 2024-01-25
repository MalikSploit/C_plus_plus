#ifndef __deviant_hpp__
#define __deviant_hpp__

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "exception"

enum class TYPE { PERSONNE, DEVIANT };

#define CITE Cite::getCite()
class Cite;


class Individu {
protected:
    inline static int compteur = 0;
    int id;

public:
    Individu();
    virtual ~Individu();
    static int getCompteur();
    virtual int getId() const;
    virtual void afficher(std::ostream & os) const;
    friend std::ostream & operator<<(std::ostream & os, const Individu& individu);
    virtual TYPE getType() const;
};


class Personne : public Individu{
private:
    std::string nom;

public:
    Personne(const std::string n);
    Personne();
    ~Personne();
    std::string getNom() const;
    void setNom(const std::string n);
    void afficher(std::ostream & os) const override;

    TYPE getType() const override;
};

class IllegalException : public std::exception{
public:
    IllegalException();
    virtual const char *what() const noexcept override;
};


class Cite{
private:
    std::vector<Individu*> residents;

public:
    void addResident(Individu* resident);
    void removeResident(int id);
    int size() const;
    static Cite & getCite();
};


class Deviant : public Individu{
private:
    std::string date;

public:
    Deviant(const Personne & personne);
    Deviant(const Personne & personne, std::string d);
    void setObs(const std::string d);
    std::string getObs() const;
    int getId() const override;
    bool operator<(const Deviant &other) const;
    TYPE getType() const override;
};

/*class MatchId{
public:
    int id;
    MatchId(int id);
    bool operator()(const Individu* resident) const;
};*/

class Covid{
private:
    std::vector<Deviant*> deviants;
    /*static bool compareByDate(const Deviant *a, const Deviant *b);*/

public:
    void push(Deviant &d);
    void pop();
    Deviant &top() const;
};

#endif
