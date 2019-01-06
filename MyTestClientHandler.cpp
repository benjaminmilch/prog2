#include "MyTestClientHandler.h"

template <class Problem, class Solution>
MyTestClientHandler<Problem, Solution>::MyTestClientHandler(Solver<Problem, Solution> solver,
        CacheManager<Problem, Solution> manager)
{
    m_solver = solver;
    m_manager = manager;
}

