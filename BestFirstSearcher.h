#ifndef PROG2_BESTFIRSTSEARCHER_H
#define PROG2_BESTFIRSTSEARCHER_H

#include "GeneralSearcher.h"

template <class T>
class BestFirstSearcher : virtual public GeneralSearcher<T> {
    int m_nodes;
public:
    explicit BestFirstSearcher(Searchable<T> *s);
    list<Node<T>*>* search() override;
    int getNumberOfNodesInSolution() override;
private:
    list<Node<T>*>* visit(Searchable<T> *searchable, Node<T> *node);
    bool isWhite(list<Node<T>*> open, list<Node<T>*> closed, Node<T> *node);
};


#endif //PROG2_BESTFIRSTSEARCHER_H
