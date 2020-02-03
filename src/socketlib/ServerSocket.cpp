#include "socketlib/ServerSocket.hpp"

namespace socketlib {
ServerSocket::ServerSocket(int port) : ServerSocket(port, 10) {
    // stub
}

ServerSocket::ServerSocket(int port, int backlog) : ServerSocket(SocketAddress("0.0.0.0", port), backlog) {
    // stub
}

ServerSocket::ServerSocket(SocketAddress address, int backlog) : _address(std::move(address)), _backlog(backlog) {
}

ServerSocket::~ServerSocket() {
    close();
}
}