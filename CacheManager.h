#ifndef PROG2_CACHEMANAGER_H
#define PROG2_CACHEMANAGER_H

template<class Problem, class Solution>
class CacheManager {
public:
    virtual bool isSolutionExist(Problem p) = 0;
    virtual Solution getSolution(Problem p) = 0;
    virtual void saveSolution(Problem p, Solution s) = 0;
};

#endif //PROG2_CACHEMANAGER_H
