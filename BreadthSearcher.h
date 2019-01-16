#ifndef PROG2_BREADTHSEARCHER_H
#define PROG2_BREADTHSEARCHER_H

#include "GeneralSearcher.h"
#include <queue>
#include <algorithm>

template <class T>
class BreadthSearcher : public GeneralSearcher<T> {
    int m_nodes;
public:
    string search(Searchable<T> *searchable) override;
    int getNumberOfNodesInSolution() override;
private:
    string visit(Searchable<T> *searchable, Node<T> *node);

    bool isWhite(list<Node<T>*> grays, Node<T> *node);
};

template <class T>
string BreadthSearcher<T>::search(Searchable<T> *searchable)
{
    m_nodes++;
    return visit(searchable, searchable->getStart());
}

template <class T>
int BreadthSearcher<T>::getNumberOfNodesInSolution()
{
    return m_nodes;
}

template <class T>
string BreadthSearcher<T>::visit(Searchable<T> *searchable, Node<T> *node)
{
    string solution = "-1";
    list<Node<T>*> grays; // visited nodes (all nodes are "white" by default)
    queue<Node<T>*> next_to_visit;
    next_to_visit.push(node); // add start node to queue
    grays.push_back(node);
    while (!next_to_visit.empty()) {
        Node<T> *current = next_to_visit.front();

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
            if (isWhite(grays, adj)) {
                grays.push_back(adj);
                next_to_visit.push(adj);
                adj->setPrevious(current);
                m_nodes++;
            }
        }
        next_to_visit.pop();
    }
    return solution; // all reachable nodes visited without reaching the end node
}

template <class T>
bool BreadthSearcher<T>::isWhite(list<Node<T> *> grays, Node<T> *node)
{
    return find(grays.begin(), grays.end(), node) == grays.end();
}

#endif //PROG2_BREADTHSEARCHER_H
