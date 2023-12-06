//
// Created by root on 11/29/23.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(int, char**) {
    const int TAILLE = 500;

    int * p = new int[TAILLE];

    for(auto i = 0; i< TAILLE; ++i ) p[i] = i;
    for(auto i = 0; i< TAILLE; ++i ) cout << p[i] << endl;

    delete [] p;

    return 0;
}