#ifndef PROG2_BREADTHSEARCHER_H
#define PROG2_BREADTHSEARCHER_H

#include "Searcher.h"

template <class T>
class BreadthSearcher : public Searcher<T> {
    int m_nodes;
public:
    list<Node<T>*>* search(Searchable<T> *searchable) override;
    int getNumberOfNodesInSolution() override;
private:
    list<Node<T>*>* visit(Searchable<T> *searchable, Node<T> *node);

    bool isWhite(list<Node<T>*> grays, Node<T> *node);
};


#endif //PROG2_BREADTHSEARCHER_H
