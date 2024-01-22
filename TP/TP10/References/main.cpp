//
// Created by root on 1/10/24.
//
#include <iostream>


class MemePasPeur {
    int tab[4];
public:
    MemePasPeur() {
        tab[0] = 1;
    }
    const int & val() const {
        return tab[0];
    }
    void modify() {
        tab[0] = 4;
    }
};

int main(int, char **) {
    MemePasPeur * p = new MemePasPeur;
    int i = p->val();
    const int & j = p->val();
    std::cout << i << " " << j << std::endl;
    p->modify();
    std::cout << i << " " << j << std::endl;
    int k = j;
    delete p;
    std::cout << i << " " << k << std::endl;
    return 0;
}