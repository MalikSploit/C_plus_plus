//
// Created by root on 12/7/23.
//
#include <iostream>
#include <cmath>

#ifndef C_CERCLE_HPP
#define C_CERCLE_HPP

class Cercle{
private:
    int x, y, rayon, ordre;
public:
    Cercle(int cx, int cy, int w, int h);
    std::string toString() const;
};

#endif //C_CERCLE_HPP
