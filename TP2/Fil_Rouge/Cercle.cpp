//
// Created by root on 11/30/23.
//

#include <iostream>
#include <cmath>

class Cercle {
private:
    int x, y;
    int rayon;
public:
    Cercle(int cx, int cy, int w, int h) : x(cx), y(cy)
    {
        rayon = std::min(w, h) / 2;
    }
    std::string toString()
    {
        return "CERCLE " + std::to_string(x) + " " + std::to_string(y)  + " " + std::to_string(rayon);

    }
};