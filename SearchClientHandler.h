//
// Created by adiel on 16/01/19.
//

#ifndef PROG2_SEARCHCLIENTHANDLER_H
#define PROG2_SEARCHCLIENTHANDLER_H

#include <strings.h>
#include <cstring>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "Searchable.h"
#include "SearchAdapter.h"
#include "MatrixReader.h"

template<class T>
class SearchClientHandler : public ClientHandler {
    Solver<Searchable<T>, string> *m_solver;
    CacheManager<Searchable<T>, string> *m_manager;
public:
    SearchClientHandler(Solver<Searchable<T>, string> *solver, CacheManager<Searchable<T>, string> *manager);

    virtual void handleClient(int sock);

};

template<class T>
SearchClientHandler<T>::SearchClientHandler(Solver<Searchable<T>, string> *solver,
                                            CacheManager<Searchable<T>, string> *manager) {
    m_solver = solver;
    m_manager = manager;
}

template<class T>
void SearchClientHandler<T>::handleClient(int sock) {
    ssize_t n;
    char buffer[256];
    MatrixReader matrixReader;

    bool gettingLines = true;
    while (gettingLines) {
        bzero(buffer, 256);
        n = read(sock, buffer, 255);
        cout << buffer << endl;

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if (strcmp(buffer, "end") == 0) {
            gettingLines = false;
        }

        matrixReader.receiveInput(buffer);
    }

    Searchable<T> *matrix = matrixReader.createMatrix();

    if (m_manager->isSolutionExist(matrix)) {
        string solution = m_manager->getSolution(matrix);
        n = write(sock, solution.c_str(), solution.length());
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    } else {
        string path = m_solver->solve(matrix);
        m_manager->saveSolution(matrix, path);
        n = write(sock, path.c_str(), path.length());
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
    ::close(sock);
}


#endif //PROG2_SEARCHCLIENTHANDLER_H
