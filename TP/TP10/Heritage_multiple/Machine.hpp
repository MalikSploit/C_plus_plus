//
// Created by root on 1/11/24.
//

#ifndef C___MACHINE_HPP
#define C___MACHINE_HPP
#include <iostream>

class Machine {
private:
    std::string type;
    int autonomie;
    int ifixit;
public:
    Machine(const std::string & type, int autonomie, int ifixit);

    std::string getType() const;
    int getAutonomie() const;
    int getIfixit() const;
};

#endif //C___MACHINE_HPP
