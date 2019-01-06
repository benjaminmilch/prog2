#ifndef PROG2_FILECACHEMANAGER_H
#define PROG2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <map>

using namespace std;

template <class Problem, class Solution>
class FileCacheManager : public CacheManager <Problem, Solution> {
    map<Problem, Solution> m_ps_map;
public:
    bool isSolutionExist(Problem p);
    Solution getSolution(Problem p);
    void saveSolution(Problem p, Solution s);
};


#endif //PROG2_FILECACHEMANAGER_H
