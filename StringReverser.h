//
// Created by adiel on 09/01/19.
//

#ifndef PROG2_STRINGREVERSER_H
#define PROG2_STRINGREVERSER_H


#include <string>
#include "Solver.h"

using namespace std;

class StringReverser : public Solver<string, string> {
public:
    virtual string solve(string p);
};


#endif //PROG2_STRINGREVERSER_H
