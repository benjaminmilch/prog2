#ifndef PROG2_SERVER_H
#define PROG2_SERVER_H

#include "ClientHandler.h"

namespace server_side
{
    class Server
    {
    public:
        virtual void open(int port, ClientHandler c) = 0;
        virtual void close() = 0;
    };
}

#endif //PROG2_SERVER_H
