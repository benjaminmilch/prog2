#include "Node.h"

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
bool Node<T>::operator<(const Node<T> *node)
{
    return m_cost < node->getCost();
}

template <class T>
bool Node<T>::operator==(const Node<T> *node)
{
    return m_cost == node->getCost();
}