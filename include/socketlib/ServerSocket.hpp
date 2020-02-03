#ifndef __SOCKETLIB_SERVER_SOCKET_HPP
#define __SOCKETLIB_SERVER_SOCKET_HPP
#pragma once

#include "socketlib/SocketAddress.hpp"
#include "socketlib/ClientSocket.hpp"

namespace socketlib {
class ServerSocket {
private:
    SocketAddress _address;
    int _backlog;

public:
    ServerSocket(int port);
    ServerSocket(int port, int backlog);
    ServerSocket(SocketAddress address, int backlog);
    ServerSocket(const ServerSocket &rhs) = delete;
    ~ServerSocket();

    ServerSocket &operator=(const ServerSocket &rhs) = delete;

    int listen();
    ClientSocket accept();
    void close();
    bool valid();
};
}
#endif