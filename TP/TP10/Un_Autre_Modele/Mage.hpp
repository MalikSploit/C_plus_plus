//
// Created by root on 1/11/24.
//

#ifndef C___MAGE_HPP
#define C___MAGE_HPP
#include "iostream"
#include "Humain.hpp"
#include "Sorcier.hpp"

class Mage : public Humain, public Sorcier {
public:
    Mage(std::string nom);
    void ensorceler() override;
};


#endif //C___MAGE_HPP
