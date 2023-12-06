//
// Created by root on 11/30/23.
//

#include <iostream>

class Bavarde {
private:
    int Inconnu;
public:
    Bavarde(int p = 0) : Inconnu(p)
    {
        std::cout << "Construction de " << Inconnu << std::endl;
    }
    ~Bavarde()
    {
        std::cout << "Tais-toi " << Inconnu << std::endl;
    }

    int get() const{
        return Inconnu;
    }
};

Bavarde bizarre(1);
Bavarde globale(2);

void fonction(Bavarde b) {
    std::cout << "code de la fonction" << std::endl;
}

int main(int, char **) {
    Bavarde b1(3);
    Bavarde b2(4);
    Bavarde * p = new Bavarde(5);
    std::cout << Bavarde(100).get() << std::endl;
    // fonction(b1);

    delete p;

    return 0;
}