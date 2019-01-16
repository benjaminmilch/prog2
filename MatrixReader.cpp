#include "MatrixReader.h"
#include "Node.h"
#include <iostream>

Matrix* MatrixReader::createMatrix()
{
    unsigned long columns = 0;
    unsigned long rows = 0;
    string line;
    string all_lines;
    vector<string> matrix_input;

    while (line != "end\n") {
        cout << "getting input:" << endl;
        getline(cin, line); // receive each line from the console from the client
        line += '\n';
        all_lines += line;
        rows++;
        cout << line << endl;
    }
    matrix_input = lineSplit(all_lines);

    // count number of columns in the matrix
    unsigned long index = 0;
    while (matrix_input[index] != "\n") {
        index++;
    }
    columns = index;
    rows -= 3;
    auto *matrix = new Matrix(rows, columns); // rows - 3 to remove the start & end points and "end"
    index = 0; // starting index for Node cost
    // loop through all rows and columns, create the appropriate Node, then add to Matrix
    for (unsigned long r = 0; r < rows; r++) {
        auto *row = new vector<Node<string>*>;
        for (unsigned long c = 0; c < columns; c++) {
            Node<string> *n = new Node<string>(to_string(r) + "," + to_string(c));
            n->setCost(stoi(matrix_input[index]));
            row->push_back(n);
            index++;
        }
        matrix->addRow(row);
        index++;
    }

    unsigned long size = matrix_input.size();
    matrix->setStart(stoul(matrix_input[size - 8]), stoul(matrix_input[size-7]));
    matrix->setEnd(stoul(matrix_input[size - 5]), stoul(matrix_input[size - 4]));

    matrix->setNodeHeuristics();

    return matrix;
}
vector<string> MatrixReader::lineSplit(string line)
{
    vector<string> strings;
    string current;
    for (char& c : line) {
        if (c != ' ' && c) {
            if (c != '\n') {
                current += c;
            } else {
                strings.push_back(current);
                current.clear();
                strings.emplace_back("\n");
            }
        } else {
            if (!current.empty()) {
                strings.push_back(current);
            }
            current.clear();
        }
    }
    return strings;
}