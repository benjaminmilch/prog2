//
// Created by adiel on 13/01/19.
//

#ifndef PROG2_TIMEOUT_EXEPTION_H
#define PROG2_TIMEOUT_EXEPTION_H

#include <stdexcept>


class timeout_exception : public std::runtime_error {
public:
    timeout_exception(const char *msg) : std::runtime_error(msg) {}

    timeout_exception(std::string msg) : std::runtime_error(msg) {}
};


#endif //PROG2_TIMEOUT_EXEPTION_H
