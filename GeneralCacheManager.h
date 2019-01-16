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
    map<Problem*, Solution> m_ps_map;
public:
    virtual bool isSolutionExist(Problem *p) const;

    virtual Solution getSolution(Problem *p) const;

    virtual void saveSolution(Problem *p, Solution s);
};

template<class Problem, class Solution>
bool GeneralCacheManager<Problem, Solution>::isSolutionExist(Problem *p) const {
    return m_ps_map.find(p) != m_ps_map.end();
}

template<class Problem, class Solution>
Solution GeneralCacheManager<Problem, Solution>::getSolution(Problem *p) const {
    return m_ps_map.at(p);
}

template<class Problem, class Solution>
void GeneralCacheManager<Problem, Solution>::saveSolution(Problem *p, Solution s) {
    m_ps_map[p] = s;
}

#endif //PROG2_GENARALCACHEMANAGER_H
