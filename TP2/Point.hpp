//
// Created by root on 11/30/23.
//

#ifndef C___POINT_H
#define C___POINT_H



class Point {
    //Par défaut, tout est privé dans une "class"
    int x;
    int y;
    static int compteur;

public:
    int getX() const;
    int getY() const;
    void setX(int number);
    void deplacerDe(int num1, int num2);
    void deplacerVers(int num1, int num2);
    static int getCompteur();

    Point();
    Point(int x, int y);
};

#endif //C___POINT_H
