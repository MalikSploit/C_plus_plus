#ifndef __SMS
#define __SMS

#include <iostream>
#include <cstring>
#include <algorithm>
#include <exception>
#include <vector>
#include <sstream>

class Reseau;
class MMS;

class Telephone{
private:
    std::string numero;
    Reseau * reseau;
    int nombreMessage;
public:
    Telephone(const std::string num="", Reseau * reseau=nullptr, int nbM=0);
    std::string getNumero() const;
    void setNumero(const std::string & num);
    Reseau * getReseau() const;
    int getNbMessages() const;
    void textoter(const std::string & num, const std::string & texte);
    void mmser(const std::string & num, MMS *mms);
};

class Reseau{
private:
    std::vector<Telephone> reseaux;
    inline static bool exception = true;
public:
    Reseau();
    void ajouter(const std::string & num);
    std::string lister();
    Telephone & trouveTel(const std::string & num);
};

class MauvaisNumero : public std::exception{
public:
    MauvaisNumero();
    const char *what() const noexcept override;
};

class Message{
private:
    std::string destinataire;
    std::string expediteur;
    std::string date;
    inline static int cle = 0;
    int id;
public:
    Message(std::string & dest, std::string & exp, std::string & d);
    virtual ~Message();
    virtual std::string afficher() const = 0;
    static int getCle();
    int getId();

};

class SMS : public Message{
private:
    std::string text;
public:
    SMS(std::string exp="", std::string dest="", std::string d="");
    SMS(const SMS & sms);
    void setTexte(const std::string t);
    std::string getTexte() const;
    std::string afficher() const override;
};

class Media{
public:
    Media();
    virtual ~Media();
    virtual std::string afficher() const = 0;
};

class Image : public Media{
public:
    Image();
    std::string afficher() const override;
};

class Son : public Media{
public:
    Son();
    std::string afficher() const override;
};

class Video : public Media{
public:
    Video();
    std::string afficher() const override;
};


class MMS : public SMS{
private:
    std::string text;
    std::vector<Media*> media;
    std::string de;
    std::string a;
public:
    MMS(std::string dest, std::string exp, std::string date);
    ~MMS();
    void joindre(Media *m);
    std::string afficher() const override;
    void setTexte(const std::string t);
    std::string getDe() const;
    std::string getA() const;
    void setDe(const std::string d);
    void setA(const std::string a);
};
#endif