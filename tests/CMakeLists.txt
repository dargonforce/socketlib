project(socketlib-tests)

option(INSTALL_GTEST "" OFF)
add_subdirectory(gtest)

file(GLOB_RECURSE test_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(socketTests ${test_sources})
target_include_directories(socketTests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(socketTests PRIVATE gtest gtest_main socketlib)
add_test(NAME socketTests COMMAND socketTests)