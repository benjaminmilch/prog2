#ifndef PROG2_MYTESTCLIENTHANDLER_H
#define PROG2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"

template <class Problem, class Solution>
class MyTestClientHandler : ClientHandler {
    Solver<Problem, Solution> m_solver;
    CacheManager<Problem, Solution> m_manager;
public:
    MyTestClientHandler(Solver<Problem, Solution> solver, CacheManager<Problem, Solution> manager);
    void handleClient(istream input, ostream output) override;
};

#endif //PROG2_MYTESTCLIENTHANDLER_H
