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
    SocketAddress(const SocketAddress &rhs);
    ~SocketAddress();

    SocketAddress &operator=(const SocketAddress &rhs);

    int getPort() const;
    std::string getAddress() const;

    static struct ::sockaddr_in toStruct(const SocketAddress &addr);
    static SocketAddress fromStruct(const struct ::sockaddr_in &addr);
    friend bool operator==(const SocketAddress &lhs, const SocketAddress &rhs);
    friend std::ostream &operator<<(std::ostream &os, const SocketAddress &addr);
};


}
#endif