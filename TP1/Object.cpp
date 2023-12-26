//
// Created by root on 11/29/23.
//
#include <iostream>

class Exemple {
public:
    void afficher() {
        std::cout << "hello" << std::endl;
    }
public :static int a;
};

int main(int, char **) {
    Exemple::a = 1;
    Exemple e;

    e.afficher();

    return 0;
}