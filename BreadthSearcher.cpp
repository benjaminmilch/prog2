#include "BreadthSearcher.h"
#include <queue>

template <class T>
BreadthSearcher<T>::BreadthSearcher(Searchable<T> *s) : GeneralSearcher<T>(s) {}

template <class T>
list<Node<T>*>* BreadthSearcher<T>::search()
{
    m_nodes = 1;
    return visit(this->searchable, this->searchable->getStart());
}

template <class T>
int BreadthSearcher<T>::getNumberOfNodesInSolution()
{
    return m_nodes;
}

template <class T>
list<Node<T>*>* BreadthSearcher<T>::visit(Searchable<T> *searchable, Node<T> *node)
{
    list<Node<T>*> grays; // visited nodes (all nodes are "white" by default)
    queue<T> next_to_visit;
    next_to_visit.push(node); // add start node to queue
    while (!next_to_visit.empty()) {
        Node<T> current = next_to_visit.pop();
        if (current.equals(searchable->getEnd())) {
            return savePath(searchable, current);
        }
        grays.push_back(current);
        for (Node<T>* &adjacent : searchable->getAdjacent(current)) {
            if (isWhite(adjacent)) {
                next_to_visit.push(adjacent);
                adjacent->setPrevious(current);
                m_nodes++;
            }
        }
    }
    return nullptr; // all reachable nodes visited without reaching the end node
}

template <class T>
bool BreadthSearcher<T>::isWhite(list<Node<T> *> grays, Node<T> *node)
{
    return find(grays.begin(), grays.end(), node) == grays.end();
}