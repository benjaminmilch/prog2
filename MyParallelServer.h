//
// Created by adiel on 13/01/19.
//

#ifndef PROG2_MYPARALLELSERVER_H
#define PROG2_MYPARALLELSERVER_H

#include "GeneralServer.h"
#include "timeout_exception.h"

class MyParallelServer : public GeneralServer{
public:
    virtual void open(int port, ClientHandler *c);

    virtual void close();
};


#endif //PROG2_MYPARALLELSERVER_H
