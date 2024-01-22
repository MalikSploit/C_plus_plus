//
// Created by root on 12/14/23.
//

#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(const std::string &msg) : message(msg){}

const char *OutOfRangeException::what() const noexcept {
    return message.c_str();
}