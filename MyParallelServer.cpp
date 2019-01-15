//
// Created by adiel on 13/01/19.
//

#include <vector>
#include <thread>
#include "MyParallelServer.h"

void ClientThread(int sock, ClientHandler *c) {
    c->handleClient(sock);
}

void MyParallelServer::open(int port, ClientHandler *c) {
    GeneralServer::open(port, c);
    int clientsSock;
    int threadIndex = 0;
    clientsSock = accept().sock_fd;
    vector<thread> threads;
    threads[threadIndex] = thread(ClientThread, clientsSock, c);
    bool running = true;
    while (running) {
        threadIndex++;
        setTimeOut(1);
        try {
            threads[threadIndex] = thread(ClientThread, clientsSock, c);
        } catch (timeout_exception) {
            running = false;
            for (int i = 0; i<threadIndex;i++){
                threads[i].join();
            }
        }
    }
}

void MyParallelServer::close() {
    GeneralServer::close();
}
