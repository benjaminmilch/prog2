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
    bool operator<(Node node); // compare COST
    bool operator==(Node node); // compare COST
};

template <class T>
Node<T>::Node(T node)
{
    m_node = node;
    m_cost = 0;
    m_previous = nullptr;
}

template <class T>
void Node<T>::setCost(double cost)
{
    m_cost = cost;
}

template <class T>
T Node<T>::getNode()
{
    return m_node;
}

template <class T>
void Node<T>::setPrevious(Node<T>* previous)
{
    m_previous = previous;
}

template <class T>
double Node<T>::getCost()
{
    return m_cost;
}

template <class T>
Node<T>* Node<T>::getPrevious()
{
    return m_previous;
}

template <class T>
bool Node<T>::equals(Node<T> *node)
{
    return m_node == node->getNode();
}

template <class T>
bool Node<T>::operator<(Node node)
{
    return m_cost < node.getCost();
}

template <class T>
bool Node<T>::operator==(Node node)
{
    return m_cost == node.getCost();
}

#endif //PROG2_NODE_H
