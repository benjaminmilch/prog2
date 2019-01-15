#include "MySerialServer.h"
#include "timeout_exception.h"

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <sys/socket.h>
#include <thread>

using namespace std;

void MySerialServer::open(int port, ClientHandler *c) {
    GeneralServer::open(port,c);
    int clint_sock = accept().sock_fd;
    c->handleClient(clint_sock);
    bool running = true;
    while (running) {
        setTimeOut(1);
        try {
            clint_sock = accept().sock_fd;
            c->handleClient(clint_sock);
        }catch (timeout_exception){
            running = false;
        }
    }
}

void MySerialServer::close() {
    GeneralServer::close();
}
