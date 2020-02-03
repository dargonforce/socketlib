#ifndef __SOCKETLIB_SOCKET_ADDRESS_HPP
#define __SOCKETLIB_SOCKET_ADDRESS_HPP
#pragma once

#include <string>

#include <netinet/in.h>
#include <arpa/inet.h>

namespace socketlib {
class SocketAddress {
private:
    std::string _address;
    int _port;

public:
    SocketAddress(std::string address, int port);
    ~SocketAddress();

    int getPort();
    std::string getAddress();

    static struct ::sockaddr_in toStruct(const SocketAddress &addr);
    static SocketAddress fromStruct(const struct ::sockaddr_in &addr);
};
}
#endif