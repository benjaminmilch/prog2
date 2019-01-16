#ifndef PROG2_MATRIX_H
#define PROG2_MATRIX_H

#include "Searchable.h"
#include <vector>

class Matrix : public Searchable<string> {
    unsigned long m_rows, m_columns;
    Node<string> *m_start, *m_end;
    vector<vector<Node<string>*>*> *m_row_nodes;
public:
    Matrix(unsigned long rows, unsigned long columns);
    void addRow(vector<Node<string>*> *row);
    void setStart(unsigned long row, unsigned long column);
    void setEnd(unsigned long row, unsigned long column);
    void setNodeHeuristics();
    Node<string>* getStart() override;
    Node<string>* getEnd() override;
    list<Node<string>*> *getAdjacent(Node<string> *node) override;
    string* SearchableToString() override;
private:
    unsigned long getRowIndex(Node<string> *node);
    unsigned long getColumnIndex(Node<string> *node);
};


#endif //PROG2_MATRIX_H
