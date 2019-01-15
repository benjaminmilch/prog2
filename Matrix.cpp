#include "Matrix.h"

Matrix::Matrix(unsigned long rows, unsigned long columns)
{
    m_rows = rows;
    m_columns = columns;
    m_row_nodes = new vector<vector<Node<string>*>*>;

   /* for (int row = 0; row < m_columns; row++) {
        auto *matrix_rows = new vector<Node<string>*>;
        m_row_nodes->push_back(matrix_rows);
        for (int col = 0; col < m_rows; col++) {
            Node<string> *node = new Node<string>(to_string(row) + "," + to_string(col));
            matrix_rows->push_back(node);
        }
    }*/
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
    if (row == 1) {
        if (column == 1) {
            if (m_row_nodes->at(row + 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row + 1)->at(column)); // below node
            }
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
        } else if (column == m_columns) {
            if (m_row_nodes->at(row + 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row + 1)->at(column)); // below node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); // left of node
            }
        } else {
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
    } else if (row == m_rows) {
        if (column == 1) {
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
        } else if (column == m_columns) {
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); // left of node
            }
        } else {
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
    } else {
        if (m_row_nodes->at(row + 1)->at(column)->getCost() != -1) {
            adjacent_nodes->push_back(m_row_nodes->at(row + 1)->at(column)); // below node
        }
        if (column == 1) {
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
        } else if (column == m_columns) {
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); // left of node
            }
        } else {
            if (m_row_nodes->at(row)->at(column + 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column + 1)); // right of node
            }
            if (m_row_nodes->at(row - 1)->at(column)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row - 1)->at(column)); // above node
            }
            if (m_row_nodes->at(row)->at(column - 1)->getCost() != -1) {
                adjacent_nodes->push_back(m_row_nodes->at(row)->at(column - 1)); //left of node
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