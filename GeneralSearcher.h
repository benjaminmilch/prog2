#ifndef PROG2_GENERALSEARCHER_H
#define PROG2_GENERALSEARCHER_H

#include "Searcher.h"

template <class T>
class GeneralSearcher : public Searcher<T>{
protected:
    Searchable<T> *m_searchable;
public:
    explicit GeneralSearcher(Searchable<T> *s);
protected:
    list<Node<T>*>* savePath(Node<T> *node);
};


#endif //PROG2_GENERALSEARCHER_H
