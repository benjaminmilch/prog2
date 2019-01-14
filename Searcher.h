#ifndef PROG2_SEARCHER_H
#define PROG2_SEARCHER_H

#include <list>
#include "Searchable.h"
#include "Node.h"

using namespace std;

template <class T>
class Searcher {
public:
    virtual list<Node<T>*>* search(Searchable<T> *searchable) = 0;
    virtual int getNumberOfNodesInSolution() = 0;
protected:
    list<Node<T>*>* savePath(Searchable<T> *searchable, Node<T> *node);
};

#endif //PROG2_SEARCHER_H
