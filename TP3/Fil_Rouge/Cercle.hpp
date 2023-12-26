//
// Created by root on 12/7/23.
//
#include <iostream>
#include "Point.hpp"
#include <cmath>
#include <sstream>
#include "Forme.hpp"

#ifndef C_CERCLE_HPP
#define C_CERCLE_HPP

class [[maybe_unused]] Cercle : public Forme{
private:
    int rayon, ordre;
public:
    Cercle(int cx, int cy, int r);
    void setOrdre(int ord);
    std::string toString() const;
};
#endif //C_CERCLE_HPP
