#include "MyTestClientHandler.h"
#include <string.h>
#include <unistd.h>
#include <string>

MyTestClientHandler::MyTestClientHandler(Solver<string, string> *solver,
                                         CacheManager<string, string> *manager) {
    m_solver = solver;
    m_manager = manager;
}


void MyTestClientHandler::handleClient(int sock) {
    ssize_t n;
    char buffer[256];

    while (true) {
        bzero(buffer, 256);
        n = read(sock, buffer, 255);
        cout << buffer << endl;

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if (strcmp(buffer, "end") == 0) {
            ::close(sock);
            break;
        }

        if (m_manager->isSolutionExist(buffer)) {
            string solution = m_manager->getSolution(buffer);
            n = write(sock, solution.c_str(), solution.length());
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        } else {
            string solution = m_solver->solve(buffer);
            m_manager->saveSolution(buffer, solution);
            n = write(sock, solution.c_str(), solution.length());
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }

    }
}