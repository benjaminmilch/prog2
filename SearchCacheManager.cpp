//
// Created by adiel on 16/01/19.
//

#include <fstream>
#include "SearchCacheManager.h"

template<class T>
bool SearchCacheManager<T>::isSolutionExist(const Searchable<T> p) const {
    return GeneralCacheManager<Searchable<T>, string>::isSolutionExist(p);
}

template<class T>
string SearchCacheManager<T>::getSolution(const Searchable<T> p) const {
    return GeneralCacheManager<Searchable<T>, string>::getSolution(p);
}

template<class T>
void SearchCacheManager<T>::saveSolution(const Searchable<T> p, const string s) {
    GeneralCacheManager<Searchable<T>, string>::saveSolution(p, s);
    ofstream file;
    file.open("searchCache.txt");
    if (file.fail()) {
        perror("ERROR fail to open file");
        exit(1);
    }
    file << "your search is:" << endl;
    file << p.toString() + '\n' +'\n' << endl;
    file << "your path is:" << endl;
    file << s << endl;
    file.close();

}

