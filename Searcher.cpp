#include "Searcher.h"

template <class T>
list<Node<T>*>* Searcher<T>::savePath(Searchable<T> *searchable, Node<T> *node)
{
    Node<T> *current = node;
    list<Node<T>*>* solution = new list<Node<T>*>*;

    while (!current->equals(searchable->getStart())) { // add all the nodes in the path from end to start
        solution->push_back(current);
        current = current->getPrevious();
    }
    solution->push_back(searchable->getStart());

    return solution;
}