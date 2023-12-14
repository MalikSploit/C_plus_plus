//
// Created by root on 12/6/23.
//

#include <iostream>

class Bavarde {
private:
    int Inconnu;
    inline static int count = 0;
public:
    explicit Bavarde(int p = 0);
    Bavarde(const Bavarde& copie); //Constructeur de copie
    ~Bavarde();

    int get() const;
    void afficher() const;
    static int getCount();
};



