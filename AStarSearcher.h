#ifndef PROG2_ASTARSEARCHER_H
#define PROG2_ASTARSEARCHER_H

#include "GeneralSearcher.h"
#include <map>

template <class T>
class AStarSearcher : public GeneralSearcher<T> {
    int m_nodes;
public:
    string search(Searchable<T> *searchable) override;
    int getNumberOfNodesInSolution() override;
private:
    bool isFlagged(Node<T> *node, list<Node<T>*> open, list<Node<T>*> closed);
    bool isClosed(Node<T> *node, list<Node<T>*> closed);
};

template <class T>
string AStarSearcher<T>::search(Searchable<T> *searchable)
{
    string solution = "-1";
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
            if (adj->equals(end)) { // stopping condition
                end->setPrevious(current);
                vector<Node<T>*> path = this->savePath(searchable, adj);
                solution.clear();
                for (unsigned long i = 0; i < path.size() - 1; i++) {
                    solution.append(searchable->getDirection(path.at(i), path.at(i + 1)));
                }
                return solution;
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

    return solution;
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
