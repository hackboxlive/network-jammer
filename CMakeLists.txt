cmake_minimum_required(VERSION 3.0)
project(network-jammer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(network-jammer)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_library(TINS_LIBRARY tins)
find_package (Threads REQUIRED)

set(SOURCE_FILES src/main.cpp src/CLI.cpp include/CLI.h src/Network.cpp include/Network.h)
add_executable(main ${SOURCE_FILES})

target_link_libraries(network-jammer "${TINS_LIBRARY}")
target_link_libraries(network-jammer ${CMAKE_THREAD_LIBS_INIT})