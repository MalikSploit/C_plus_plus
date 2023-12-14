//
// Created by root on 12/10/23.
//

#include "../../TP2/Bavarde.hpp"

void test1(const Bavarde& b) {
    std::cout << "appel de fonction avec paramètre objet et copie" << std::endl;
}

Bavarde test2a() {
    std::cout << "appel de fonction avec retour" << std::endl;
    return Bavarde(); // création d'un objet local
}

Bavarde test2b() {
    Bavarde b; // création d'un objet local
    std::cout << "appel de fonction avec retour" << std::endl;
    return b;
}

void test3(Bavarde& b) {
    std::cout << "appel de fonction avec référence" << std::endl;
}

void test4(Bavarde* b) {
    std::cout << "appel de fonction avec un pointeur sur un objet" << std::endl;
}

int main(){
    Bavarde b1(3);
    test1(b1);
    test2a();
    test2b();
    test3(b1);
    test4(&b1);

    std::cout << "Nombre d'instances de Bavarde : " << Bavarde::getCount() << std::endl;

    return 0;
}