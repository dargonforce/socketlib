#include <gtest/gtest.h>
#include <socketlib/SocketAddress.hpp>

using namespace socketlib;

TEST(SocketAddress_test, BasicCreation) {
    const std::string address = "127.0.0.1";
    const int port = 45;
    SocketAddress sockAddr(address, port);
    ASSERT_EQ(sockAddr.getPort(), port);
    ASSERT_STREQ(sockAddr->getAddress(), address);
}