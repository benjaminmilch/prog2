#include "AStarSearcher.h"

template <class T>
AStarSearcher<T>::AStarSearcher(Searchable<T> *s) : GeneralSearcher<T>(s) {}

template <class T>
list<Node<T>*>* AStarSearcher<T>::search()
{

}

template <class T>
int AStarSearcher<T>::getNumberOfNodesInSolution()
{
    return m_nodes;
}

template <class T>
list<Node<T>*>* AStarSearcher<T>::visit(Node<T> *node)
{

}

template <class T>
bool AStarSearcher<T>::isWhite(Node<T> *node)
{

}

