#include "BestFirstSearcher.h"


template <class T>
BestFirstSearcher<T>::BestFirstSearcher(Searchable<T> *s) : GeneralSearcher<T>(s) {}

template <class T>
list<Node<T>*>* BestFirstSearcher<T>::search()
{
    m_nodes = 1;
    return visit(this->m_searchable, this->m_searchable->getStart());
}

template <class T>
int BestFirstSearcher<T>::getNumberOfNodesInSolution()
{
    return m_nodes;
}

template <class T>
list<Node<T>*>* BestFirstSearcher<T>::visit(Searchable<T> *searchable, Node<T> *node)
{
    list<Node<T>*> open;
    list<Node<T>*> closed;
    Node<T> * current = node;
    open.push(current); // push the start node into the list

    while (!open.empty()) {
        current = open.pop_front();
        closed.push_back(current);
        if (current->equals(searchable->getEnd())) {
            return savePath(searchable, current);
        }
        for (Node<T>* &adjacent : searchable->getAdjacent(current)) {
            if (isWhite(adjacent)) {
                open.push_back(adjacent);
                adjacent->setPrevious(current);
                m_nodes++;
            }
        }
        open.sort();
    }
    return nullptr; // all reachable nodes visited without reaching the end node
}

template <class T>
bool BestFirstSearcher<T>::isWhite(list<Node<T> *> open, list<Node<T>*> closed, Node<T> *node)
{
    return find(open.begin(), open.end(), node) == open.end()
           && find(closed.begin(), closed.end(), node) == closed.end();
}