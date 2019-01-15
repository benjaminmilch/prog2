#include "GeneralSearcher.h"


template <class T>
GeneralSearcher<T>::GeneralSearcher(Searchable<T> *s)
{
    m_searchable = s;
}
template <class T>
list<Node<T>*>* GeneralSearcher<T>::savePath(Node<T> *node)
{
    Node<T> *current = node;
    list<Node<T>*>* solution = new list<Node<T>*>*;

    while (!current->equals(m_searchable->getStart())) { // add all the nodes in the path from end to start
        solution->push_back(current);
        current = current->getPrevious();
    }
    solution->push_back(m_searchable->getStart());

    return solution;
}