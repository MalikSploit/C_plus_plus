//
// Created by root on 12/14/23.
//

#ifndef C___OUTOFRANGEEXCEPTION_HPP
#define C___OUTOFRANGEEXCEPTION_HPP
#include <exception>
#include <iostream>

class OutOfRangeException : public std::exception {
private:
    std::string message;
public:
    explicit OutOfRangeException(const std::string &msg);

    virtual const char *what() const noexcept override;
};

#endif //C___OUTOFRANGEEXCEPTION_HPP
