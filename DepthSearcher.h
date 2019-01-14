#ifndef PROG2_DEPTHSEARCHER_H
#define PROG2_DEPTHSEARCHER_H

#include "Searcher.h"

template <class T>
class DepthSearcher : public Searcher<T> {
    int m_nodes;
public:
    list<Node<T>*>* search(Searchable<T> *searchable) override;
    int getNumberOfNodesInSolution() override;
private:
    list<Node<T>*>* visit(Searchable<T> *searchable, list<Node<T>*> grays, list<Node<T>*> blacks, Node<T> *node);
    bool isWhite(list<Node<T>*> grays, list<Node<T>*> blacks, Node<T> *node);
};


#endif //PROG2_DEPTHSEARCHER_H
