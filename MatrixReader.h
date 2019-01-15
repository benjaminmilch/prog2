#ifndef PROG2_MATRIXREADER_H
#define PROG2_MATRIXREADER_H

#include "Matrix.h"
#include <string>
#include <vector>

using namespace std;
class MatrixReader {
public:
    Matrix* createMatrix();
    vector<string> lineSplit(string line);
};


#endif //PROG2_MATRIXREADER_H
