#include "socketlib/SocketAddress.hpp"

namespace socketlib {
SocketAddress::SocketAddress(std::string address, int port) : _address(std::move(address)), _port(port) {
    // stub
}

SocketAddress::~SocketAddress() = default;

int SocketAddress::getPort() {
    return _port;
}

std::string SocketAddress::getAddress() {
    return _address;
}
}