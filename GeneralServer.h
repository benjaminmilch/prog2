//
// Created by adiel on 13/01/19.
//

#ifndef PROG2_GENERALSERVER_H
#define PROG2_GENERALSERVER_H

#include "Server.h"
#include "Sockets.h"

using namespace server_side;
using namespace posix_sockets;

class GeneralServer : public Server {
    TCP_socket m_sock;
public:
    virtual void initializeServer(int port);

    virtual void listen(int max_lis);

    virtual void setTimeOut(int sec, int usec = 0);

    virtual TCP_socket accept();

    virtual void open(int port, ClientHandler *c);

    virtual void close();
};


#endif //PROG2_GENERALSERVER_H
