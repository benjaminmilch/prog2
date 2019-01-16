#ifndef PROG2_SEARCHABLE_H
#define PROG2_SEARCHABLE_H

#include "Node.h"
#include <string>
#include <list>

using namespace std;

template <class T>
class Searchable {
public:
    virtual Node<T>* getStart() = 0;
    virtual Node<T>* getEnd() = 0;
    virtual list<Node<T>*> *getAdjacent(Node<T> *node) = 0;
    virtual string* SearchableToString() = 0;
};

#endif //PROG2_SEARCHABLE_H
