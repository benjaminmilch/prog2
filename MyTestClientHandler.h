#ifndef PROG2_MYTESTCLIENTHANDLER_H
#define PROG2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"


class MyTestClientHandler : public ClientHandler {
    Solver<string, string>* m_solver;
    CacheManager<string, string>* m_manager;
public:
    MyTestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *manager);
    void handleClient(int sock) override;
};

#endif //PROG2_MYTESTCLIENTHANDLER_H
