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
        m_ps_map.insert({key, val});
    }
    file.close();
}

void FileCacheManager::saveSolution(const string p, const string s) {
    m_ps_map[p] = s;
}

string FileCacheManager::getSolution(const string p) const {
    return m_ps_map.at(p);
}

bool FileCacheManager::isSolutionExist(const string p) const{
    return (m_ps_map.find(p) != m_ps_map.end());
}

void FileCacheManager::save() {
    ofstream file;
    file.open("fileCache.txt");
    if (file.fail()) {
        perror("ERROR fail to open file");
        exit(1);
    }

    file.clear();

    for (auto i: m_ps_map) {
        file << i.first + '|' + i.second << endl;
    }

    file.close();
}