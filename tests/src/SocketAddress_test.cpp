#include <gtest/gtest.h>
#include "socketlib/SocketAddress.hpp"

using namespace socketlib;

TEST(SocketAddress_test, BasicCreation) {
    const std::string address = "127.0.0.1";
    const int port = 45;
    SocketAddress sockAddr(address, port);
    ASSERT_EQ(sockAddr.getPort(), port);
    ASSERT_EQ(sockAddr.getAddress(), address);
}

TEST(SocketAddress_test, ToFromStruct) {
    const std::string address = "127.0.0.1";
    const int port = 47;
    const SocketAddress sockAddr(address, port);
    auto addrIn = SocketAddress::toStruct(sockAddr);
    auto sockAddr2 = SocketAddress::fromStruct(addrIn);
    ASSERT_EQ(sockAddr, sockAddr2);
}
