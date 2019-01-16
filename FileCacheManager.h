#ifndef PROG2_FILECACHEMANAGER_H
#define PROG2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "GeneralCacheManager.h"
#include <string>
#include <map>

using namespace std;

class FileCacheManager : public GeneralCacheManager<string, string> {
public:
    FileCacheManager();

    virtual bool isSolutionExist(string *p) const;

    virtual string getSolution(string *p) const;

    virtual void saveSolution(string *p, string s);
};


#endif //PROG2_FILECACHEMANAGER_H
