cmake_minimum_required(VERSION 3.6)
project(network-jammer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(network-jammer)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_library(TINS_LIBRARY tins)
find_package (Threads REQUIRED)

set(SOURCE_FILES main.cpp command_line.cpp command_line.hpp network.cpp network.hpp)
add_executable(network-jammer ${SOURCE_FILES})

target_link_libraries(network-jammer "${TINS_LIBRARY}")
target_link_libraries(network-jammer ${CMAKE_THREAD_LIBS_INIT})