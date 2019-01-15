#ifndef PROG2_FILECACHEMANAGER_H
#define PROG2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <map>

using namespace std;

class FileCacheManager : public CacheManager<string, string> {
    map<string, string> m_ps_map;
public:
    FileCacheManager();

    virtual bool isSolutionExist(const string p) const;

    virtual string getSolution(const string p) const;

    virtual void saveSolution(const string p, const string s);

    virtual void save();

    ~FileCacheManager();
};


#endif //PROG2_FILECACHEMANAGER_H
