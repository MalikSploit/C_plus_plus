//
// Created by root on 11/30/23.
//

#include <iostream>
#include <string>

class Rectangle {
private:
    int x, y, w, h;
public:
    Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h){}
    std::string toString()
    {
        return "RECTANGLE " + std::to_string(x)  + " " + std::to_string(y) + " " + std::to_string(w) + " " + std::to_string(h);
    }
};