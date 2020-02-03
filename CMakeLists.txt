cmake_minimum_required(VERSION 3.14)
project(socketlib)

enable_testing()

file(GLOB_RECURSE socket_sources 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(socket ${socket_sources})
target_include_directories(socket PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_subdirectory(tests)