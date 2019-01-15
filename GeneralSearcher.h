#ifndef PROG2_GENERALSEARCHER_H
#define PROG2_GENERALSEARCHER_H

#include "Searcher.h"

template <class T>
class GeneralSearcher : public Searcher<T>{
protected:
    Searchable<T> *m_searchable;
public:
    explicit GeneralSearcher(Searchable<T> *s);
protected:
    list<Node<T>*>* savePath(Node<T> *node);
};

template <class T>
GeneralSearcher<T>::GeneralSearcher(Searchable<T> *s)
{
    m_searchable = s;
}

template <class T>
list<Node<T>*>* GeneralSearcher<T>::savePath(Node<T> *node)
{
    Node<T> *current = node;
    auto *solution = new list<Node<T>*>;

    while (!current->equals(m_searchable->getStart())) { // add all the nodes in the path from end to start
        solution->push_back(current);
        current = current->getPrevious();
    }
    solution->push_back(m_searchable->getStart());

    return solution;
}


#endif //PROG2_GENERALSEARCHER_H
