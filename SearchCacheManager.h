//
// Created by adiel on 16/01/19.
//

#ifndef PROG2_SEARCHCACHEMANAGER_H
#define PROG2_SEARCHCACHEMANAGER_H

#include <fstream>
#include "GeneralCacheManager.h"
#include "Searchable.h"

using namespace std;

template<class T>
class SearchCacheManager : public GeneralCacheManager<Searchable<T>, string> {
    map<T, Searchable<T> *> m_str_map;
public:
    virtual bool isSolutionExist(Searchable<T> *p) const;

    virtual string getSolution(Searchable<T> *p) const;

    virtual void saveSolution(Searchable<T> *p, string s);
};

template<class T>
bool SearchCacheManager<T>::isSolutionExist(Searchable<T> *p) const {
    return m_str_map.find(p->SearchableToString()) != m_str_map.end();
}

template<class T>
string SearchCacheManager<T>::getSolution(Searchable<T> *p) const {
    return GeneralCacheManager<Searchable<T>, string>::getSolution(m_str_map.at(p->SearchableToString()));
}

template<class T>
void SearchCacheManager<T>::saveSolution(Searchable<T> *p, string s) {
    GeneralCacheManager<Searchable<T>, string>::saveSolution(p, s);
    m_str_map.insert({p->SearchableToString(), p});
    ofstream file;
    file.open("searchCache.txt");
    if (file.fail()) {
        perror("ERROR fail to open file");
        exit(1);
    }
    file << p->SearchableToString() << endl;
    file << "end" << endl;
    file << s << endl;
    file.close();

}


#endif //PROG2_SEARCHCACHEMANAGER_H
