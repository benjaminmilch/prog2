#ifndef PROG2_DEPTHSEARCHER_H
#define PROG2_DEPTHSEARCHER_H

#include "GeneralSearcher.h"
#include <list>

template <class T>
class DepthSearcher : virtual public GeneralSearcher<T> {
    int m_nodes;
public:
    explicit DepthSearcher(Searchable<T> *searchable);
    list<Node<T>*>* search() override;
    int getNumberOfNodesInSolution() override;
private:
    list<Node<T>*>* visit(Searchable<T> *searchable, list<Node<T>*> grays, list<Node<T>*> blacks, Node<T> *node);
    bool isWhite(list<Node<T>*> grays, list<Node<T>*> blacks, Node<T> *node);
};


#endif //PROG2_DEPTHSEARCHER_H
