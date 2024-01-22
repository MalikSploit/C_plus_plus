//
// Created by root on 1/11/24.
//

#include "Machine.hpp"

Machine::Machine(const std::string &t, int a, int i) : type(t), autonomie(a), ifixit(i) {}

std::string Machine::getType() const{
    return type;
}
int Machine::getAutonomie() const{
    return autonomie;
}
int Machine::getIfixit() const{
    return ifixit;
}