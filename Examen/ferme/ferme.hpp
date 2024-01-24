#ifndef ferme__hpp
#define ferme__hpp

#include <iostream>
#include "exception"
#include "vector"
#include "memory"
#include "algorithm"

class Produit{
private:
    std::string nom;
public:
    Produit(const std::string n);
    std::string getNom() const;
    bool isEqual(const Produit p) const;
    bool operator==(const Produit & p) const;
    friend std::ostream & operator<<(std::ostream & os, const Produit & p);
};

class PeutPasProduireException : public std::exception{
public:
    PeutPasProduireException();
    const char *what() const noexcept override ;
};

class Communiquer{
public:
    Communiquer();
    virtual ~Communiquer();
    virtual void communiquer(std::ostream & os) = 0;
};

class Animal : public Communiquer{
protected:
    int malade;
    inline static int compteur = 0;
public:
    Animal();
    Animal(const Animal & other);
    virtual ~Animal();
    virtual Produit produire() const = 0;
    virtual std::string getNom() const = 0;
    virtual std::string typeAnimal() const = 0;
    void setMalade(bool mal);
    static int getCompteur();
};

class Vache : public Animal{
private:
    std::string surnom;
public:
    Vache(const std::string sn);
    std::string getNom() const override;
    Produit produire() const override;
    void meugler(std::ostream &os) const;
    void communiquer(std::ostream & os) override;
    std::string typeAnimal() const override;
};

class Poule : public Animal{
private:
    std::string surnom;
public:
    Poule(std::string sn);
    std::string getNom() const override;
    Produit produire() const override;
    void glousser(std::ostream & os) const;
    void communiquer(std::ostream & os) override;
    std::string typeAnimal() const override;
};

class Ferme{
private:
    std::vector<Animal*> animaux;
public:
    Ferme();
    ~Ferme();
    void acheter(Animal *animal);
    int size();
    void nourrirAnimaux(std::ostream & os);
    Animal *vendre(const std::string & nom);
};

#endif
