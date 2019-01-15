#ifndef PROG2_CACHEMANAGER_H
#define PROG2_CACHEMANAGER_H

template<class Problem, class Solution>
class CacheManager {
public:
    virtual bool isSolutionExist(const Problem p) const = 0;
    virtual Solution getSolution(const Problem p) const = 0;
    virtual void saveSolution(const Problem p,const Solution s) = 0;
    virtual void save() = 0;
};

#endif //PROG2_CACHEMANAGER_H
