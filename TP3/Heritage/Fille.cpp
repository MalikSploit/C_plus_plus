//
// Created by root on 12/6/23.
//
#include "Mere.hpp"

class Fille: public Mere{
public:
    /*Fille(std::string nom) : Mere(nom) {
    }*/
    using Mere::Mere;
    void afficher() override
    {
        std::cout << "Fille : " << getName() <<std::endl;
    }
};