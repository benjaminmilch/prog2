//
// Created by adiel on 16/01/19.
//

#include "SearchAdapter.h"

template<class Problem, class Solution>
Solution SearchAdapter<Problem, Solution>::solve(Problem p) {
    return s->search(p);
}

template<class Problem, class Solution>
SearchAdapter<Problem, Solution>::SearchAdapter(Searcher<Problem> *s):s(s) {}
