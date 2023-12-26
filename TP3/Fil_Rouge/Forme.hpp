//
// Created by root on 12/7/23.
//
#include "Point.hpp"

#ifndef C_FORME_HPP
#define C_FORME_HPP

enum class COULEURS { NOIR, BLANC, BLEU, VERT, ROUGE, JAUNE };

class Forme{
private:
    inline static int nbFormes = 0;
    Point point;
    COULEURS couleur;
    int id;

public:
    Forme();
    Forme(const Point& p, COULEURS c);
    Point getPoint() const;
    void setX(int x);
    void setY(int y);
    COULEURS getCouleur() const;
    void setCouleur(COULEURS c);
    int getId() const;
    static int prochainId();
    virtual ~Forme();
};

#endif //C_FORME_HPP