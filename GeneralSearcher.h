#ifndef PROG2_GENERALSEARCHER_H
#define PROG2_GENERALSEARCHER_H

#include "Searcher.h"

template <class T>
class GeneralSearcher : public Searcher<T>{
protected:
    list<Node<T>*>* savePath(Searchable<T> *searchable, Node<T> *node);
};

template <class T>
list<Node<T>*>* GeneralSearcher<T>::savePath(Searchable<T>* searchable, Node<T> *node)
{
    Node<T> *current = node;
    auto *solution = new list<Node<T>*>;

    while (!current->equals(searchable->getStart())) { // add all the nodes in the path from end to start
        solution->push_back(current);
        current = current->getPrevious();
    }
    solution->push_back(searchable->getStart());
    solution->reverse();
    return solution;
}


#endif //PROG2_GENERALSEARCHER_H
