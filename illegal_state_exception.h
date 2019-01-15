//
// Created by adiel on 13/01/19.
//

#ifndef PROG2_ILLEGAL_STATE_EXCEPTION_H
#define PROG2_ILLEGAL_STATE_EXCEPTION_H

#include <stdexcept>

namespace posix_sockets{
    class illegal_state_exception : public std::logic_error
    {
    public:
        illegal_state_exception(std::string msg) : std::logic_error(msg){}
    };
}
#endif //PROG2_ILLEGAL_STATE_EXCEPTION_H
