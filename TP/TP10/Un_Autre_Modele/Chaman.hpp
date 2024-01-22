//
// Created by root on 1/11/24.
//

#ifndef C___CHAMAN_HPP
#define C___CHAMAN_HPP
#include "Elfe.hpp"
#include "Sorcier.hpp"


class Chaman : public Elfe, public Sorcier {
public:
    Chaman(std::string nom);
    void ensorceler() override;
};


#endif //C___CHAMAN_HPP
