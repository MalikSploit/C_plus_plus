//
// Created by root on 12/7/23.
//

#include <string>
#include "Point.hpp"
#include "sstream"
#include "Forme.hpp"

#ifndef C_RECTANGLE_HPP
#define C_RECTANGLE_HPP

class Rectangle : public Forme{
private:
    int w, h, ordre;
public:
    Rectangle(int x, int y, int w, int h);
    void setOrdre(int ordre);
    std::string toString() const;
};

#endif //C_RECTANGLE_HPP
