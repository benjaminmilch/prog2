#ifndef PROG2_BESTFIRSTSEARCHER_H
#define PROG2_BESTFIRSTSEARCHER_H

#include "Searcher.h"

template <class T>
class BestFirstSearcher : public Searcher<T> {
    int m_nodes;
public:
    list<Node<T>*>* search(Searchable<T> *searchable) override;
    int getNumberOfNodesInSolution() override;
private:
    list<Node<T>*>* visit(Searchable<T> *searchable, Node<T> *node);
    bool isWhite(list<Node<T>*> open, list<Node<T>*> closed, Node<T> *node);
};


#endif //PROG2_BESTFIRSTSEARCHER_H
