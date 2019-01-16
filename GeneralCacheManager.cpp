//
// Created by adiel on 16/01/19.
//

#include "GeneralCacheManager.h"

template<class Problem, class Solution>
bool GeneralCacheManager<Problem, Solution>::isSolutionExist(const Problem p) const {
    return (m_ps_map.find(p) != m_ps_map.end());
}

template<class Problem, class Solution>
Solution GeneralCacheManager<Problem, Solution>::getSolution(const Problem p) const {
    return m_ps_map.at(p);
}

template<class Problem, class Solution>
void GeneralCacheManager<Problem,Solution>::saveSolution(const Problem p, const Solution s) {
    m_ps_map[p] = s;
}