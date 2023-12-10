//
// Created by root on 12/7/23.
//

#include <string>

#ifndef C_RECTANGLE_HPP
#define C_RECTANGLE_HPP

class Rectangle{
private:
    int x, y, w, h, ordre;
public:
    Rectangle(int x, int y, int w, int h);
    std::string toString() const;
};

#endif //C_RECTANGLE_HPP
