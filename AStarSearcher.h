#ifndef PROG2_ASTARSEARCHER_H
#define PROG2_ASTARSEARCHER_H

#include "Searcher.h"

template <class T>
class AStarSearcher : public Searcher<T> {
    int m_nodes;
public:
    list<Node<T>*>* search(Searchable<T> *searchable) override;
    int getNumberOfNodesInSolution() override;
private:
    list<Node<T>*>* visit(Searchable<T> *searchable, Node<T> *node);
    bool isWhite(Node<T> *node);
};


#endif //PROG2_ASTARSEARCHER_H
