#ifndef PROG2_CLIENTHANDLER_H
#define PROG2_CLIENTHANDLER_H

#include <iostream>

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(int sock) = 0;
};

#endif //PROG2_CLIENTHANDLER_H
