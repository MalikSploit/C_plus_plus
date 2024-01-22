//
// Created by root on 1/11/24.
//

#ifndef C___HUMAIN_HPP
#define C___HUMAIN_HPP
#include <iostream>

enum Genre{
    Homme,
    Femme
};

class Humain {
private:
    std::string nom;
    Genre genre;
    int age;
public:
    Humain(const std::string &n, Genre g, int a);
    std::string getNom() const;
    Genre getGenre() const;
    int getAge() const;
    void setNom(const std::string &n);
    void setGenre(const Genre g);
    void setAge(const int a);
};


#endif //C___HUMAIN_HPP
