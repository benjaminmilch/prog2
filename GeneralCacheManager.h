//
// Created by adiel on 16/01/19.
//

#ifndef PROG2_GENARALCACHEMANAGER_H
#define PROG2_GENARALCACHEMANAGER_H

#include "CacheManager.h"
#include <map>

using namespace std;

template<class Problem, class Solution>
class GeneralCacheManager : public CacheManager<Problem, Solution> {
protected:
    map<Problem,Solution> m_ps_map;
public:
    virtual bool isSolutionExist(const Problem p) const;

    virtual Solution getSolution(const Problem p) const;

    virtual void saveSolution(const Problem p, const Solution s);
};


#endif //PROG2_GENARALCACHEMANAGER_H
