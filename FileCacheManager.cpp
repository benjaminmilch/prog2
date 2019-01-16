#include "FileCacheManager.h"
#include <fstream>
#include <string>
#include <string.h>

FileCacheManager::FileCacheManager() {
    ifstream file;
    file.open("fileCache.txt");
    if (file.fail()) {
        return;
    }
    string line;
    while (getline(file, line)) {
        string key, val;
        unsigned long i = 0;
        unsigned long length = line.length();
        while (line[i] != '|') {
            key += line[i];
            i++;
        }
        i++;
        while (i < length) {
            val += line[i];
            i++;
        }
        m_ps_map.insert({&key, val});
    }
    file.close();
}

bool FileCacheManager::isSolutionExist(string* p) const {
    return GeneralCacheManager::isSolutionExist(p);
}

string FileCacheManager::getSolution(string* p) const {
    return GeneralCacheManager::getSolution(p);
}

void FileCacheManager::saveSolution(string* p, string s) {
    GeneralCacheManager::saveSolution(p, s);
    ofstream file;
    file.open("fileCache.txt");
    if (file.fail()) {
        perror("ERROR fail to open file");
        exit(1);
    }

    file << *p + '|' + s << endl;
    file.close();
}
