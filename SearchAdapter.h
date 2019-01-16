//
// Created by adiel on 16/01/19.
//

#ifndef PROG2_SERCHADAPTER_H
#define PROG2_SERCHADAPTER_H

#include "Searcher.h"
#include "Solver.h"

template<class Problem, class Solution>
class SearchAdapter : public Solver<Problem, Solution> {
    Searcher<Problem> *s;
public:
    SearchAdapter(Searcher<Problem> *s);

    virtual Solution solve(Problem p);

};


#endif //PROG2_SERCHADAPTER_H
