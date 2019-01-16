#ifndef PROG2_DEPTHSEARCHER_H
#define PROG2_DEPTHSEARCHER_H

#include "GeneralSearcher.h"
#include <list>
#include <algorithm>

template <class T>
class DepthSearcher : virtual public GeneralSearcher<T> {
    int m_nodes;
public:
    list<Node<T>*>* search(Searchable<T> *searchable) override;
    int getNumberOfNodesInSolution() override;
private:
    list<Node<T>*>* visit(Searchable<T> *searchable, list<Node<T>*> grays, list<Node<T>*> blacks, Node<T> *node);
    bool isWhite(list<Node<T>*> grays, list<Node<T>*> blacks, Node<T> *node);
};

template <class T>
list<Node<T>*>* DepthSearcher<T>::search(Searchable<T> *searchable)
{
    list<Node<T>*> grays; // visited nodes, but not finished
    list<Node<T>*> blacks; // finished nodes (by default, all nodes start as "white")
    m_nodes++;
    return visit(searchable, grays, blacks, searchable->getStart());
}

template <class T>
int DepthSearcher<T>::getNumberOfNodesInSolution()
{
    return m_nodes;
}

template <class T>
list<Node<T>*>* DepthSearcher<T>::visit(Searchable<T> *searchable, list<Node<T> *> grays,
                                        list<Node<T> *> blacks, Node<T> *node)
{
    grays.push_back(node); // mark node as "visited" (gray)

    if (node->equals(searchable->getEnd())) { // stopping condition
        return this->savePath(searchable, node);
    }

    list<Node<T>*> adjacent = *(searchable->getAdjacent(node));
    for (Node<T>* &adj : adjacent) {
        if (isWhite(grays, blacks, adj)) {
            m_nodes++;
            adj->setPrevious(node);
            return visit(searchable, grays, blacks, adj);
        }
    }

    grays.remove(node);
    blacks.push_back(node);

   // if () { // all reachable nodes visited without reaching the end node
      //return nullptr;
    //}
}

template <class T>
bool DepthSearcher<T>::isWhite(list<Node<T> *> grays, list<Node<T> *> blacks, Node<T> *node)
{
    return find(grays.begin(), grays.end(), node) == grays.end()
           && find(blacks.begin(), blacks.end(), node) == blacks.end();
}

#endif //PROG2_DEPTHSEARCHER_H
