#ifndef PROG2_NODE_H
#define PROG2_NODE_H

template <class T>
class Node {
    T m_node;
    int m_cost;
    int m_g_cost;
    unsigned long m_heuristic;
    int m_f_value;
    Node<T>* m_previous;
public:
    explicit Node(T node);
    void setPrevious(Node<T>* previous);
    void setCost(int cost);
    void setGCost(int g);
    void setHeuristic(unsigned long heuristic);
    void setFValue(int f);
    T getNode();
    int getCost();
    int getGCost();
    int getHeuristic();
    int getFValue();
    Node<T>* getPrevious();
    bool equals(Node<T> *node); // compare NODE members
    bool operator<(Node node); // compare COST members
    bool operator==(Node node); // compare COST members
};

template <class T>
Node<T>::Node(T node)
{
    m_node = node;
    m_cost = 0;
    m_g_cost = 0;
    m_heuristic = 0;
    m_f_value = 0;
    m_previous = nullptr;
}

template <class T>
void Node<T>::setCost(int cost)
{
    m_cost = cost;
}

template <class T>
void Node<T>::setGCost(int g)
{
    m_g_cost = g;
}

template <class T>
void Node<T>::setHeuristic(unsigned long heuristic)
{
    m_heuristic = heuristic;
}

template <class T>
void Node<T>::setFValue(int f)
{
    m_f_value = f;
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
int Node<T>::getCost()
{
    return m_cost;
}

template <class T>
int Node<T>::getGCost()
{
    return m_g_cost;
}

template <class T>
int Node<T>::getHeuristic()
{
    return m_heuristic;
}

template <class T>
int Node<T>::getFValue()
{
    return m_f_value;
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
