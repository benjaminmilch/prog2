//
// Created by adiel on 09/01/19.
//

#include "StringReverser.h"

string StringReverser::solve(string p) {
    unsigned long length = p.length();
    string rev;
    for (int i = 0; i < length; i++){
        rev = p[i] + rev;
    }
    return rev;
}