#ifndef PROG2_BREADTHSEARCHER_H
#define PROG2_BREADTHSEARCHER_H

#include "GeneralSearcher.h"

template <class T>
class BreadthSearcher : public GeneralSearcher<T> {
    int m_nodes;
public:
    explicit BreadthSearcher(Searchable<T> *s);
    list<Node<T>*>* search() override;
    int getNumberOfNodesInSolution() override;
private:
    list<Node<T>*>* visit(Searchable<T> *searchable, Node<T> *node);

    bool isWhite(list<Node<T>*> grays, Node<T> *node);
};


#endif //PROG2_BREADTHSEARCHER_H
