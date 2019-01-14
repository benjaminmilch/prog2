#include "MatrixReader.h"
#include <iostream>

Matrix* MatrixReader::createMatrix()
{
    unsigned long columns = 0;
    unsigned long rows = 0;
    string line;
    string all_lines;
    vector<string> matrix_input;

    while (line != "end") {
        getline(cin, line); // receive each line from the console from the client
        line += " \n ";
        all_lines += line;
        rows++;
    }
    matrix_input = lineSplit(all_lines);

    // count number of columns in the matrix
    unsigned long index = 0;
    while (matrix_input[index] != "\n") {
        index++;
    }
    columns = index;

    auto *matrix = new Matrix(rows - 3, columns); // rows - 3 to remove the start & end points and "end"
    unsigned long size = matrix_input.size();
    matrix->setStart(stoul(matrix_input[size - 8]), stoul(matrix_input[size-7]));
    matrix->setEnd(stoul(matrix_input[size - 5]), stoul(matrix_input[size - 4]));

    index = 0; // starting index for Node cost
    auto *row = new vector<Node<string>*>;
    // loop through all rows and columns, create the appropriate Node, then add to Matrix
    for (unsigned long r = 1; r <= rows; r++) {
        row->clear();
        for (unsigned long c = 1; c <= columns; c++) {
            row->push_back(new Node<string>(to_string(r) + "," + to_string(c)));
            row->back()->setCost(stod(matrix_input[index]));
            index++;
        }
        matrix->addRow(row);
        index++;
    }

    return matrix;
}
vector<string> MatrixReader::lineSplit(string line)
{
    vector<string> strings;
    string current;
    for (char& c : line) {
        if (c != ' ') {
            current += c;
        } else {
            if (!current.empty()) {
                strings.push_back(current);
            }
            current.clear();
        }
    }
    return strings;
}