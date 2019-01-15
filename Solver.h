#ifndef PROG2_SOLVER_H
#define PROG2_SOLVER_H

template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem p) = 0;
};

#endif //PROG2_SOLVER_H
