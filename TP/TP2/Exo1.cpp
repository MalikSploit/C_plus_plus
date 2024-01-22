//
// Created by root on 11/30/23.
//


#include <iostream>
#include "Point.hpp"

int main(int, char**){
    /*Point p;
    std::cout << p.getX() << std::endl;
    p.setX(100);
    std::cout << p.getX();

    p.deplacerDe(10, 10);
    std::cout << p.getX() << std::endl;
    std::cout << p.getY() << std::endl;
    p.deplacerVers(100, 100);
    std::cout << p.getX() << std::endl;
    std::cout << p.getY() << std::endl;*/

    Point p1;
    Point p2(5, 10);

    auto* p3 = new Point();
    auto* p4 = new Point(10, 20);

    std::cout << "Contenu de P1.x = " << p1.getX() << std::endl;
    std::cout << "Contenu de P1.y = " << p1.getY() << std::endl;

    std::cout << "Contenu de P2.x = " << p2.getX() << std::endl;
    std::cout << "Contenu de P2.y = " << p2.getY() << std::endl;

    std::cout << "Contenu de P3.x = " << p3->getX() << std::endl;
    std::cout << "Contenu de P3.y = " << p3->getY() << std::endl;

    std::cout << "Contenu de P4.x = " << p4->getX() << std::endl;
    std::cout << "Contenu de P4.y = " << p4->getY() << std::endl;

    std::cout << "Nombre d'objets Point créés: " << Point::getCompteur() << std::endl;

    delete p4;
    delete p3;

    return 0;
}