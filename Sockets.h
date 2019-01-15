//
// Created by adiel on 13/01/19.
//

#ifndef PROG2_SOCKET_H
#define PROG2_SOCKET_H


#include <sys/socket.h>
#include <system_error>
#include <unistd.h>

namespace posix_sockets {
    struct TCP_socket {
        int sock_fd;

        TCP_socket() {
            sock_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (sock_fd < 0) {
                throw std::system_error(std::error_code(errno, std::generic_category()), "failure on opening socket");
            }
        }

        TCP_socket(int open_sock_fd) {
            this->sock_fd = open_sock_fd;
        }

        void close() {
            if (::close(sock_fd) < 0) {
                throw std::system_error(std::error_code(errno, std::generic_category()), "failure on closing socket");
            }
        }

        void setTimeOut(int sec, int usec = 0) {
            timeval timeout;
            timeout.tv_sec = sec;
            timeout.tv_usec = usec;

            // setting socket option for recieve timeout
            if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO,
                           (char *) &timeout, sizeof(timeout)) == -1) {
                throw std::system_error(std::error_code(errno, std::generic_category()), "failure on setsockopt");
            }
        }
    };
}

#endif //PROG2_SOCKET_H
