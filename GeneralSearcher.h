#ifndef PROG2_GENERALSEARCHER_H
#define PROG2_GENERALSEARCHER_H

#include <vector>
#include <algorithm>
#include "Searcher.h"

template <class T>
class GeneralSearcher : public Searcher<T>{
public:
    virtual T search(Searchable<T> *searchable) = 0;
protected:
    vector<Node<T>*> savePath(Searchable<T> *searchable, Node<T> *node);
};

template <class T>
vector<Node<T>*> GeneralSearcher<T>::savePath(Searchable<T>* searchable, Node<T> *node)
{
    Node<T> *current = node;
    vector<Node<T>*> solution;

    while (!current->equals(searchable->getStart())) { // add all the nodes in the path from end to start
        solution.push_back(current);
        current = current->getPrevious();
    }
    solution.push_back(searchable->getStart());
    reverse(begin(solution), end(solution));
    return solution;
}


#endif //PROG2_GENERALSEARCHER_H
