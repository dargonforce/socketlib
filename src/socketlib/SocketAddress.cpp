#include "socketlib/SocketAddress.hpp"

#include <cstring>

namespace socketlib {
SocketAddress::SocketAddress(std::string address, int port) : _address(std::move(address)), _port(port) {
    // stub
}

SocketAddress::SocketAddress(const SocketAddress &rhs) = default;

SocketAddress::~SocketAddress() = default;

SocketAddress &SocketAddress::operator=(const SocketAddress &rhs) = default;

int SocketAddress::getPort() const {
    return _port;
}

std::string SocketAddress::getAddress() const {
    return _address;
}

struct ::sockaddr_in SocketAddress::toStruct(const SocketAddress &addr) {
    struct ::sockaddr_in rv;
    std::memset(&rv, 0, sizeof(rv));
    rv.sin_family = AF_INET;
    rv.sin_port = htons(addr.getPort());
    const auto address = addr.getAddress();
    inet_aton(address.c_str(), std::addressof(rv.sin_addr));
    return rv;
}

SocketAddress SocketAddress::fromStruct(const struct ::sockaddr_in &addr) {
    const int port = addr.sin_port;
    char ip[INET_ADDRSTRLEN];
    inet_ntop(addr.sin_family, std::addressof(addr.sin_addr), ip, INET_ADDRSTRLEN);
    const std::string address(ip);
    return SocketAddress(address, port);
}

bool operator==(const SocketAddress &lhs, const SocketAddress &rhs) {
    
    return lhs.getPort() == rhs.getPort() && lhs.getAddress() == rhs.getAddress();
}
}