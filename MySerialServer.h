#ifndef PROG2_MYSERIALSERVER_H
#define PROG2_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;

class MySerialServer : Server {
public:
    void open(int port, ClientHandler c) override;
    void close() override;
};


#endif //PROG2_MYSERIALSERVER_H
