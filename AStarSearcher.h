#ifndef PROG2_ASTARSEARCHER_H
#define PROG2_ASTARSEARCHER_H

#include "GeneralSearcher.h"

template <class T>
class AStarSearcher : public GeneralSearcher<T> {
    int m_nodes;
public:
    explicit AStarSearcher(Searchable<T> *s);
    list<Node<T>*>* search() override;
    int getNumberOfNodesInSolution() override;
private:
    list<Node<T>*>* visit(Node<T> *node);
    bool isWhite(Node<T> *node);
};


#endif //PROG2_ASTARSEARCHER_H
