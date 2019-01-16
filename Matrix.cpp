#include "Matrix.h"

Matrix::Matrix(unsigned long rows, unsigned long columns)
{
    m_rows = rows;
    m_columns = columns;
    m_row_nodes = new vector<vector<Node<string>*>*>;
}

void Matrix::addRow(vector<Node<string> *> *row)
{
    m_row_nodes->push_back(row);
}
void Matrix::setStart(unsigned long row, unsigned long column)
{
    m_start = m_row_nodes->at(row)->at(column);
}

void Matrix::setEnd(unsigned long row, unsigned long column)
{
    m_end = m_row_nodes->at(row)->at(column);
}

void Matrix::setNodeHeuristics()
{
    unsigned long heuristic;
    unsigned long row, column;
    unsigned long end_row = getRowIndex(m_end) + 1;
    unsigned long end_column = getColumnIndex(m_end) + 1;

    for (unsigned long i = 0; i < m_row_nodes->size(); i++) {
        for (unsigned long j = 0; j < m_row_nodes->at(i)->size(); j++) {
            if (m_row_nodes->at(i)->at(j)->getCost() != -1) {
                row = getRowIndex(m_row_nodes->at(i)->at(j)) + 1;
                column = getColumnIndex(m_row_nodes->at(i)->at(j)) + 1;
                if (row > end_row) {
                    heuristic = row - end_row;
                } else {
                    heuristic = end_row - row;
                }
                if (column > end_row) {
                    heuristic += (column - end_column);
                } else {
                    heuristic += (end_column - column);
                }
                m_row_nodes->at(i)->at(j)->setHeuristic(heuristic);
            }
        }
    }
}

Node<string>* Matrix::getStart()
{
    return m_start;
}

Node<string>* Matrix::getEnd()
{
    return m_end;
}

list<Node<string>*>* Matrix::getAdjacent(Node<string> *node)
{
    unsigned long row = getRowIndex(node);
    unsigned long column = getColumnIndex(node);
    auto *adjacent_nodes = new list<Node<string>*>;
    // maintain the rule of (down, right, up, left) for direction order
    if (row == 0) { // top row of matrix
        if (column == 0) { // left column of matrix
            if (m_row_nodes->at(row + 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row + 1)->at(column)); // below node
            }
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
        } else if (column == m_columns - 1) { // right column of matrix
            if (m_row_nodes->at(row + 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row + 1)->at(column)); // below node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); // left of node
            }
        } else { // one of the middle columns of the matrix
            if (m_row_nodes->at(row + 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row + 1)->at(column)); // below node
            }
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); // left of node
            }
        }
    } else if (row == m_rows - 1) { // bottom row of the matrix
        if (column == 0) { // left column of the matrix
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
        } else if (column == m_columns - 1) { // right column of the matrix
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); // left of node
            }
        } else { // one of the middle columns of the matrix
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); // left of node
            }
        }
    } else { // one of the middle rows of the matrix
        if (column == 0) { // left column of the matrix
            if (m_row_nodes->at(row + 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row + 1)->at(column)); // below node
            }
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
        } else if (column == m_columns - 1) { // right column of the matrix
            if (m_row_nodes->at(row + 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row + 1)->at(column)); // below node
            }
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); // left of node
            }
        } else { // one of the middle columns of the matrix
            if (m_row_nodes->at(row + 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row + 1)->at(column)); // below node
            }
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); // left of node
            }
        }
    }
    return adjacent_nodes;
}

unsigned long Matrix::getRowIndex(Node<string> *node)
{
    string temp = node->getNode();
    string row;
    for (char& c : temp) {
        if (c == ',') {
            break;
        }
        row += c;
    }
    return stoul(row);
}

unsigned long Matrix::getColumnIndex(Node<string> *node)
{
    string temp = node->getNode();
    string column;
    bool flag = false;
    for (char& c : temp) {
        if (flag) {
            column += c;
        } else {
            if (c == ',') {
                flag = true;
            }
        }
    }
    return stoul(column);
}

string* Matrix::SearchableToString()
{
    auto* matrix = new string();
    for (unsigned long i = 0; i < m_row_nodes->size(); i++) {
        for (unsigned long j = 0; j < m_row_nodes->at(i)->size(); j++) {
            matrix->append(to_string(m_row_nodes->at(i)->at(j)->getCost()) + " ");
        }
        matrix->append("\n");
    }

    return matrix;
}