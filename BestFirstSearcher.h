#ifndef PROG2_BESTFIRSTSEARCHER_H
#define PROG2_BESTFIRSTSEARCHER_H

#include "GeneralSearcher.h"
#include <vector>

template <class T>
class BestFirstSearcher : virtual public GeneralSearcher<T> {
    int m_nodes;
public:
    string search(Searchable<T> *searchable) override;
    int getNumberOfNodesInSolution() override;
private:
    string visit(Searchable<T> *searchable, Node<T> *node);
    bool isWhite(list<Node<T>*> open, list<Node<T>*> closed, Node<T> *node);
    void mergeSort(vector<Node<T>*> &open, unsigned long first, unsigned long last);
    void merge(vector<Node<T>*> &open, unsigned long first, unsigned long middle, unsigned long last);
};

template <class T>
string BestFirstSearcher<T>::search(Searchable<T> *searchable)
{
    m_nodes++;
    return visit(searchable, searchable->getStart());
}

template <class T>
int BestFirstSearcher<T>::getNumberOfNodesInSolution()
{
    return m_nodes;
}

template <class T>
string BestFirstSearcher<T>::visit(Searchable<T> *searchable, Node<T> *node)
{
    string solution = "-1";
    list<Node<T>*> open;
    list<Node<T>*> closed;
    vector<Node<T>*> open_copy;
    Node<T> * current = node;
    open.push_back(current); // push the start node into the list

    while (!open.empty()) {
        current = open.front();
        open.pop_front();
        closed.push_back(current);

        if (current->equals(searchable->getEnd())) { // stopping condition
            vector<Node<T>*> path = this->savePath(searchable, current);
            solution.clear();
            for (unsigned long i = 0; i < path.size() - 1; i++) {
                solution.append(searchable->getDirection(path.at(i), path.at(i + 1)));
            }
            return solution;
        }

        list<Node<T>*> adjacent = *(searchable->getAdjacent(current));
        for (Node<T>* &adj : adjacent) {
            if (isWhite(open, closed, adj)) {
                open.push_back(adj);
                adj->setPrevious(current);
                m_nodes++;
            }
        }
        while (!open.empty()) {
            open_copy.push_back(open.front());
            open.pop_front();
        }
        mergeSort(open_copy, 0, open_copy.size()-1);
        for (unsigned long i = 0; i < open_copy.size(); i++) {
            open.push_back(open_copy[i]);
        }
        open_copy.clear();
    }
    return solution; // all reachable nodes visited without reaching the end node
}

template <class T>
bool BestFirstSearcher<T>::isWhite(list<Node<T> *> open, list<Node<T>*> closed, Node<T> *node)
{
    return find(open.begin(), open.end(), node) == open.end()
           && find(closed.begin(), closed.end(), node) == closed.end();
}

template <class T>
void BestFirstSearcher<T>::mergeSort(vector<Node<T>*> &open, unsigned long first, unsigned long last)
{
    if (first < last) {
        unsigned long middle = first + (last - first) / 2;

        mergeSort(open, first, middle);
        mergeSort(open, middle + 1, last);

        merge(open, first, middle, last);
    }
}

template <class T>
void BestFirstSearcher<T>::merge(vector<Node<T> *> &open, unsigned long first, unsigned long middle,
                                 unsigned long last)
{
    unsigned long i, j, k;
    unsigned long n = middle - first + 1;
    unsigned long m = last - middle;

    vector<Node<T>*> left = vector<Node<T>*>();
    vector<Node<T>*> right = vector<Node<T>*>();

    for (i = 0; i < n; i++) {
        left.push_back(open[first + i]);
    }
    for (j = 0; j < m; j++) {
        right.push_back(open[middle + 1 + j]);
    }

    i = 0;
    j = 0;
    k = first;
    while (i < n && j < m) {
        if ((*left[i]) < (*right[j])) {
            open[k] = left[i];
            i++;
        } else {
            open[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        open[k] = left[i];
        i++;
        k++;
    }

    while (j < m) {
        open[k] = right[j];
        j++;
        k++;
    }
}
#endif //PROG2_BESTFIRSTSEARCHER_H
