#ifndef PROG2_ASTARSEARCHER_H
#define PROG2_ASTARSEARCHER_H

#include "GeneralSearcher.h"
#include <map>

template <class T>
class AStarSearcher : public GeneralSearcher<T> {
    int m_nodes;
public:
    list<Node<T>*>* search(Searchable<T> *searchable) override;
    int getNumberOfNodesInSolution() override;
private:
    bool isFlagged(Node<T> *node, list<Node<T>*> open, list<Node<T>*> closed);
    bool isClosed(Node<T> *node, list<Node<T>*> closed);
};

template <class T>
list<Node<T>*>* AStarSearcher<T>::search(Searchable<T> *searchable)
{
    list<Node<T>*> open; // nodes to be checked
    list<Node<T>*> closed; // checked nodes
    Node<T> *start = searchable->getStart();
    Node<T> *end = searchable->getEnd();
    Node<T> *current;
    open.push_back(start);
    m_nodes++;

    while (!open.empty()) {
        current = open.front();
        open.remove(current);
        closed.push_back(current);
        list<Node<T>*> adjacent = *(searchable->getAdjacent(current));
        for (Node<T>* &adj : adjacent) {
            if (adj->equals(end)) {
                end->setPrevious(current);
                return this->savePath(searchable, end);
            }

            if (!isFlagged(adj, open, closed)) { // new node encountered
                open.push_back(adj);
                adj->setGCost(adj->getCost() + current->getGCost());
                adj->setFValue(adj->getGCost() + adj->getHeuristic());
                adj->setPrevious(current);
            } else {
                if (!isClosed(adj, closed)) { // node is not closed
                    if (current->getGCost() + adj->getCost() < adj->getGCost()) { // cheaper from current node
                        adj->setPrevious(current);
                        adj->setGCost(adj->getCost() + current->getGCost());
                        adj->setFValue(adj->getGCost() + adj->getHeuristic());
                    }
                }
            }
        }

        Node<T> *front = open.front();
        size_t size = 0;
        for (Node<T>* &node : open) { // place the Node with the smallest F value at the front of the open list
            if (size < open.size()) {
                if (node->getFValue() < front->getFValue()) {
                    open.remove(node);
                    open.push_front(node);
                    front = node;
                }
                size++;
            } else {
                break;
            }
        }
    }

    return nullptr;
}

template <class T>
int AStarSearcher<T>::getNumberOfNodesInSolution()
{
    return m_nodes;
}


template <class T>
bool AStarSearcher<T>::isFlagged(Node<T> *node, list<Node<T>*> open, list<Node<T>*> closed)
{
    return find(open.begin(), open.end(), node) != open.end()
           || find(closed.begin(), closed.end(), node) != closed.end();
}

template <class T>
bool AStarSearcher<T>::isClosed(Node<T> *node, list<Node<T> *> closed)
{
    return find(closed.begin(), closed.end(), node) != closed.end();
}

#endif //PROG2_ASTARSEARCHER_H
