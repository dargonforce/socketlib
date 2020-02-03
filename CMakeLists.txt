cmake_minimum_required(VERSION 3.14)
project(socketlib)

enable_testing()

file(GLOB_RECURSE socket_sources 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(socketlib ${socket_sources})
target_include_directories(socketlib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_subdirectory(tests)