//
// Created by root on 11/30/23.
//
#include "Rectangle.cpp"
#include "Cercle.cpp"

int main()
{
    Rectangle rectangle(4,4, 5, 10);
    std::cout << rectangle.toString() << std::endl;

    Cercle cercle(4,4, 5, 10);
    std::cout << cercle.toString() << std::endl;
    return 0;
}