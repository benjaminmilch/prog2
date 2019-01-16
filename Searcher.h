#ifndef PROG2_SEARCHER_H
#define PROG2_SEARCHER_H

#include <list>
#include "Searchable.h"

using namespace std;

template <class T>
class Searcher {
public:
    virtual list<Node<T>*>* search(Searchable<T> *searchable) = 0;
    virtual int getNumberOfNodesInSolution() = 0;
};

#endif //PROG2_SEARCHER_H
