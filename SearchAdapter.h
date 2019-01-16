//
// Created by adiel on 16/01/19.
//

#ifndef PROG2_SERCHADAPTER_H
#define PROG2_SERCHADAPTER_H

#include "Searcher.h"
#include "Solver.h"

template<class Problem, class Solution, class T>
class SearchAdapter : public Solver<Problem, Solution> {
    Searcher<T> *m_sercher;
public:
    SearchAdapter(Searcher<T> *searcher);

    virtual Solution solve(Problem *p);
};

template<class Problem, class Solution, class T>
SearchAdapter<Problem, Solution, T>::SearchAdapter(Searcher<T> *searcher) {
    m_sercher = searcher;
}

template<class Problem, class Solution, class T>
Solution SearchAdapter<Problem, Solution, T>::solve(Problem *p) {
    return m_sercher->search(p);
}


#endif //PROG2_SERCHADAPTER_H
