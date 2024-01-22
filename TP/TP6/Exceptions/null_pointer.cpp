//
// Created by root on 12/14/23.
//

#include <stdexcept>

class null_pointer : public std::logic_error{
public:
    null_pointer() : std::logic_error("Operation on null pointer") {}
};