//
// Created by root on 12/11/23.
//

#ifndef C_CHAINE_HPP
#define C_CHAINE_HPP
#include <iostream>
#include <cstring>

class Chaine {
private:
    int capa;
    char *tab;

public:
    Chaine();
    explicit Chaine(int pCapa);
    Chaine(const char * cstr);
    Chaine(const Chaine &uC);
    ~Chaine();

    int getCapacite() const;
    const char* c_str() const;
    void remplacer(const char *c);
    void afficher(std::ostream& os=std::cout) const;
    char & operator[](int index);
    const char& operator[](int index) const;
    Chaine& operator=(const Chaine &uC);

    friend std::ostream & operator<<(std::ostream& os, const Chaine& ch);
};


#endif //C_CHAINE_HPP
