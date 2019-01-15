//
// Created by adiel on 13/01/19.
//

#include "GeneralServer.h"
#include "timeout_exception.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <sys/socket.h>
#include <thread>

void GeneralServer::initializeServer(int port) {
    sockaddr_in addr_in;
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(port);
    addr_in.sin_addr.s_addr = INADDR_ANY;

    if (bind(m_sock.sock_fd, (sockaddr *) &addr_in, sizeof(addr_in)) == -1) {
        throw std::system_error(std::error_code(errno, std::generic_category()), "failure on bind");
    }
}

void GeneralServer::listen(int max_lis) {
    if (::listen(m_sock.sock_fd, max_lis) == -1) {
        throw std::system_error(std::error_code(errno, std::generic_category()), "error on listen");
    }
}

void GeneralServer::setTimeOut(int sec, int usec) {
    m_sock.setTimeOut(sec, usec);
}

TCP_socket GeneralServer::accept() {
    sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int client_sock_fd = ::accept(m_sock.sock_fd, (sockaddr *) &addr, &len);
    if (client_sock_fd < 0) {
        // eagain and ewouldblock are errors normally hapenning on timeouts
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            throw timeout_exception("timeout on accept");
        } else {
            throw std::system_error(std::error_code(errno, std::generic_category()), "error on accept");
        }
    }
    TCP_socket client_sock(client_sock_fd);
    return client_sock;
}

void GeneralServer::open(int port, ClientHandler *c) {
    initializeServer(port);
    listen(5);
}

void GeneralServer::close() {
    m_sock.close();
}
