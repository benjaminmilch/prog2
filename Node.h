#ifndef PROG2_NODE_H
#define PROG2_NODE_H

template <class T>
class Node {
    T m_node;
    double m_cost;
    Node<T>* m_previous;
public:
    explicit Node(T node);
    void setPrevious(Node<T>* previous);
    void setCost(double cost);
    T getNode();
    double getCost();
    Node<T>* getPrevious();
    bool equals(Node<T> *node);
    bool operator<(const Node<T> *node); // compare COST
    bool operator==(const Node<T> *node); // compare COST
};

#endif //PROG2_NODE_H
