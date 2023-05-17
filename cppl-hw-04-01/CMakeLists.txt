cmake_minimum_required(VERSION 3.22.0)
project(cppl-hw-04-01)
add_executable(cppl-04-01 cppl-hw-04-01.cpp)

add_subdirectory(../Catch2 Catch2-build)
add_executable(cppl-04-01test test-main.cpp cppl-hw-04-01.cpp)
target_link_libraries(cppl-04-01test  PRIVATE Catch2::Catch2)
