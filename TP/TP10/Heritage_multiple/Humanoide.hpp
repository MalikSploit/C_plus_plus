//
// Created by root on 1/11/24.
//

#ifndef C___HUMANOIDE_HPP
#define C___HUMANOIDE_HPP
#include "Humain.hpp"
#include "Machine.hpp"

class Humanoide : public Humain, public Machine {
public:
    Humanoide(const std::string &nom, const std::string& type, Genre genre, int age);
};


#endif //C___HUMANOIDE_HPP
