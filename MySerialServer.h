#ifndef PROG2_MYSERIALSERVER_H
#define PROG2_MYSERIALSERVER_H

#include "Server.h"
#include "GeneralServer.h"

using namespace server_side;

class MySerialServer : public GeneralServer {
public:
    void open(int port, ClientHandler *c) override;

    void close() override;
};


#endif //PROG2_MYSERIALSERVER_H
