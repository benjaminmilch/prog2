//
// Created by adiel on 16/01/19.
//

#ifndef PROG2_SEARCHCACHEMANAGER_H
#define PROG2_SEARCHCACHEMANAGER_H

#include "GeneralCacheManager.h"
#include "Searchable.h"
using namespace std;
template <class T>
class SearchCacheManager : public GeneralCacheManager<Searchable<T>, string>{
public:
    virtual bool isSolutionExist(const Searchable<T> p) const;

    virtual string getSolution(const Searchable<T> p) const;

    virtual void saveSolution(const Searchable<T> p, const string s);
};


#endif //PROG2_SEARCHCACHEMANAGER_H
